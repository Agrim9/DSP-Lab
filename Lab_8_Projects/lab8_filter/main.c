#include "data_types.h"
#include "dma_setup.h"
#include "i2s_setup.h"
#include "register_system.h"
#include "register_cpu.h"
#include "aic3204.h"
#include "hwafft.h"
#include "lowpass.h"		//filter coefficients are provided in this header file. 

#define PLL_100M 1 /* Set PLL system clock to 100MHz */
#define PLL_98M  0
#define PLL_40M  0
#define PLL_12M  0

#define overlap 11 // COEFF length-1 

Int16 PingPongFlagInL;  //these flag will be high when DMA has finished transferring data into PONG buffer  
Int16 PingPongFlagInR;  //these flags are being modified by DMA_ISR() function
Int16 PingPongFlagOutL;
Int16 PingPongFlagOutR;

/* Buffers for DMA in/out */
Int16 DMA_InpL[PING_PONG_SIZE];		//first half of these buffer will be used as PING buffer
Int16 DMA_InpR[PING_PONG_SIZE];		//second part will be used as PONG buffer
Int16 DMA_OutL[PING_PONG_SIZE];
Int16 DMA_OutR[PING_PONG_SIZE];

/* Buffers for processing */
Int16 BufferL[FFT_LENGTH];
Int16 BufferR[FFT_LENGTH];

Int16 realL[FFT_LENGTH];
Int16 realR[FFT_LENGTH];

Int16 imagL[FFT_LENGTH];
Int16 imagR[FFT_LENGTH];

Int16 BufferL_out[FFT_LENGTH];
// Add declarations of your own buffers here for uniformity.
Int16 pad_coef[FFT_LENGTH];
Int16 real_fftcoef[FFT_LENGTH];
Int16 imag_fftcoef[FFT_LENGTH];
Int16 imag_tempop[FFT_LENGTH];
Int16 real_tempop[FFT_LENGTH];
Int16 temp_t[FFT_LENGTH];
Int16 past_vals[11]={0,0,0,0,0,0,0,0,0,0,0};
/* --- Special buffers required for HWAFFT ---*/
#pragma DATA_SECTION(complex_buffer, "cmplxBuf");
Int32 complex_buffer[PING_PONG_SIZE];

#pragma DATA_SECTION(bitreversed_buffer, "brBuf");
#pragma DATA_ALIGN(bitreversed_buffer, 2*FFT_LENGTH);
Int32 bitreversed_buffer[FFT_LENGTH];

#pragma DATA_SECTION(temporary_buffer,"tmpBuf");
Int32 temporary_buffer[FFT_LENGTH];
/* -------------------------------------------*/

void InitSystem(void);
void ConfigPort(void);
void SYS_GlobalIntEnable(void);
void SYS_GlobalIntDisable(void);
void do_fft(Int16 *real_data, Int16 *fft_real, Int16 *fft_imag, Uint16 scale);
void do_ifft(Int16 *fft_real, Int16 *fft_imag, Int16 *ifft_data, Uint16 scale);

/* Choose AIC3204 sampling rate */
short fs = AIC3204_FS_48KHZ;

void main(void) 
{
	Uint16 i;
	
	InitSystem();
	ConfigPort();
	
	SYS_GlobalIntEnable(); /* Enable global interrupts */
	IER0 = 0x0100;         /* Enable DMA0 interrupt */

    I2S0_setup();          /* Setup I2S0 */

	AIC3204_Init();        /* Initialize AIC3204 */

	DMA0_setup();          /* Setup DMA0 CH0-3 */
   	
   	I2S0_enable();         /* Enable I2S0 */         
   	DMA0_enable_CH(0);	   /* Enable DMA0CH0 */
 
   	DMA0_enable_CH(1);	   /* Enable DMA0CH1 */
   	
   	DMA0_enable_CH(2);	   /* Enable DMA0CH2 */	
   	 
   	DMA0_enable_CH(3);	   /* Enable DMA0CH3 */	

	/**************************HINT**********************************/
	// pad appropriate number of zeros to COEFF array and take its FFT using do_fft() function
	// You might want to use a separate buffer to do this.
	for(i=0;i<FFT_LENGTH;i++)
	{
	    if(i<12) {
	        pad_coef[i]=COEFFS[i];
	    }
	    else {
	        pad_coef[i]=0;
	    }
	}
	do_fft(pad_coef,real_fftcoef,imag_fftcoef,1);

	/* Begin infinite loop */
	while (1) 
	{ 
		if (PingPongFlagInL && PingPongFlagInR) 
		{
			for (i = 0; i < PING_PONG_SIZE/2; i++)
			{
				BufferL[i+overlap] = DMA_InpL[i + PING_PONG_SIZE/2];
				BufferR[i+overlap] = DMA_InpR[i + PING_PONG_SIZE/2];
			}

		} 
		else 
		{
			for (i = 0; i < PING_PONG_SIZE/2; i++)
			{
				BufferL[i+overlap] = DMA_InpL[i];
				BufferR[i+overlap] = DMA_InpR[i];
			}

		}
		

		/**************************HINT**********************************/
        // Where do the first 'overlap' values in the input block come from?
		
		do_fft(BufferL, realL, imagL, 1);
		
		/**************************HINT**********************************/
		// obtain the frequency response of the output block.
		// Now, inverse transform it to get the output block in time domain and store it in BufferL_out
		for(i=0;i<FFT_LENGTH;i++)
		{
		    real_tempop[i]=realL[i]*real_fftcoef[i]-imagL[i]*imag_fftcoef[i];
		    imag_tempop[i]=imagL[i]*real_fftcoef[i]+realL[i]*imag_fftcoef[i];
		}
		do_ifft(real_tempop,imag_tempop,BufferL_out,1);

		/**************************HINT**********************************/
		  // Save the current input buffer for future reference.

        if (PingPongFlagOutL && PingPongFlagOutR)
        {

			for (i = 0; i < PING_PONG_SIZE/2; i++)
			{
        		DMA_OutL[i + PING_PONG_SIZE/2] = BufferL_out[i+overlap];
				DMA_OutR[i + PING_PONG_SIZE/2] = BufferL_out[i+overlap];
        	}
        } 
        else 
        {
			for (i = 0; i < PING_PONG_SIZE/2; i++)
			{								  /*******HINT******/
        		DMA_OutL[i] = BufferL_out[i+overlap]; //modify this code
				DMA_OutR[i] = BufferL_out[i+overlap]; //its not correct
        	}
        }
	}

}

/* ======================== Initialize DSP System Clock =========================  */
/* ------------------------------------------------------------------------------  */
/* For more info see SPRUFX5D - Section 1.4.3.2.6 (copying below for reference:)   */
/* You can follow the steps below to program the PLL of the DSP clock generator.   */ 
/* The recommendation is to stop all peripheral operation before changing the PLL  */ 
/* frequency, with the exception of the device CPU and USB. The device CPU must be */
/* operational to program the PLL controller. Software is responsible for ensuring */
/* the PLL remains in BYPASS_MODE for at least 4 ms before switching to PLL_MODE.  */
/* 1. Make sure the clock generator is in BYPASS MODE by setting SYSCLKSEL = 0.    */
/* 2. Program RDRATIO, M, and RDBYPASS in CGCR1 and CGCR2 according to your        */
/*    required settings.														   */
/* 3. Program ODRATIO and OUTDIVEN in CGCR4 according to your required settings.   */
/* 4. Write 0806h to the INIT field of CGCR3.									   */
/* 5. Set PLL_PWRDN = 0.														   */
/* 6. Wait 4 ms for the PLL to complete its phase-locking sequence.				   */
/* 7. Place the clock generator in its PLL MODE by setting SYSCLKSEL = 1.		   */
/* ------------------------------------------------------------------------------  */
/* Note: This is a suggested sequence. It is most important to have all 		   */ 
/* programming done before the last step to place the clock generator in PLL MODE. */
/* =============================================================================== */
void InitSystem(void)
{
	Uint16 i;
	
	/*Clock Configuration Register 2 (CCR2) - Section 1.4.4.6 */
    CONFIG_MSW = 0x0; /* System Clock Generator is in Bypass Mode */

#if  (PLL_100M == 1)
	/* CGCR2 - Section 1.4.4.2 */
    PLL_CNTL2 = 0x8000; /* Bypass reference divider */
    /* CGCR4 - Section 1.4.4.4 */
    PLL_CNTL4 = 0x0000; /* Bypass output divider */
    /* CGCR3 - Section 1.4.4.3 */
    PLL_CNTL3 = 0x0806; /* initialization bits */
    /* CGCR1 - Section 1.4.4.1 */
    /* PLL power up. PLL Multiplier M = 1000 */
    PLL_CNTL1 = 0x8BE8; //PG1.4: 0x82FA;

#elif (PLL_12M == 1)
    PLL_CNTL2 = 0x8000;
    PLL_CNTL4 = 0x0200;
    PLL_CNTL3 = 0x0806;
    PLL_CNTL1 = 0x82ED;

#elif (PLL_98M == 1)    
    PLL_CNTL2 = 0x8000;
    PLL_CNTL4 = 0x0000;
    PLL_CNTL3 = 0x0806;
    PLL_CNTL1 = 0x82ED;

#elif (PLL_40M == 1)        
    PLL_CNTL2 = 0x8000;
    PLL_CNTL4 = 0x0300;
    PLL_CNTL3 = 0x0806;
    PLL_CNTL1 = 0x8262;    
#endif

    while ( (PLL_CNTL3 & 0x0008) == 0);
    
	/*Clock Configuration Register 2 (CCR2) - Section 1.4.4.6 */
    CONFIG_MSW = 0x1; /* System Clock Generator is in PLL Mode */

    /* Peripheral Clock Gating Configuration Register 1 (PCGCR1) - Section 1.5.3.2.1 */
    IDLE_PCGCR = 0x0020; /* System clock and other clocks active */
    					 /* According to Table 1-24 bit 5 should be always set to 1 */
    /* Peripheral Clock Gating Configuration Register 2 (PCGCR2) - Section 1.5.3.2.1 */
    IDLE_PCGCR_MSW = 0x007D; /* Enable SAR clock */
    
	/* Peripheral Software Reset Counter Register (PSRCR) - Section 1.7.5.1 */
    PER_RSTCOUNT = 0x08; /* Software reset signals asserted after 2 clock cycles */
    					 /* NOTE: p.75 states this value must be at least 0x08   */
    /* Peripheral Reset Control Register (PRCR) - Section 1.7.5.2 */
    PER_RESET = 0x00FF; /* Reset ALL peripherals */
    
    for (i=0; i< 0xFFFF; i++);
}

/* ========================= Configure External Busses ==========================  */
/* ------------------------------------------------------------------------------  */
/* For more info see SPRUFX5D - Section 1.7.3.1									   */
/* =============================================================================== */
void ConfigPort(void)
{
    Int16 i;
    
    /* External Bus Selection Register (EBSR) - Section 1.7.3.1 */
    PERIPHSEL0 = 0x6900; /* PPMODE = 110 - Mode 6 */
    					 /* SP1MODE = 10 - Mode 2 */
						 /* SP0MODE = 01 - Mode 1 */
						 
    for (i=0; i< 0xFFF; i++);
}

void SYS_GlobalIntEnable(void)
{
    asm(" BIT (ST1, #ST1_INTM) = #0");
}

void SYS_GlobalIntDisable(void)
{
    asm(" BIT (ST1, #ST1_INTM) = #1");
}

/* ---------------- Wrapper function to implement HWAFFT ---------------- */
/* For more information see: Application Report - SPRABB6A, June 2010     */
/* Note that there are also several discussions in e2e.ti.com forums.     */
/* The appropriate functions are linked via c5515.cmd. See also:          */
/* http://e2e.ti.com/support/dsp/c5000/f/109/p/49635/176118.aspx#176118   */
/*																		  */
/* The function requires pre-allocated arrays for input data (16-bit Q15) */
/* and real and imaginray parts of the FFT.                               */
/* ---------------------------------------------------------------------- */
void do_fft(Int16 *real_data, Int16 *fft_real, Int16 *fft_imag, Uint16 scale)
{
	Uint16 i, data_selection;
	Int32 *complex_data, *bitrev_data, *temp_data, *fft_data;
	
	/* Initialize relevant pointers */
	bitrev_data  = bitreversed_buffer;
	temp_data    = temporary_buffer;
	complex_data = complex_buffer;
	
	/* Convert real data to "pseudo"-complex data (real, 0) */
	/* Int32 complex = Int16 real (MSBs) + Int16 imag (LSBs) */
	for (i = 0; i < FFT_LENGTH; i++) {
		*(complex_data + i) = ( (Int32) (*(real_data + i)) ) << 16;
	}
	
	/* Perform bit-reversing */
	hwafft_br(complex_data, bitrev_data, FFT_LENGTH);
	
	/* Perform FFT */
	if (scale) {
		data_selection = hwafft_256pts(bitrev_data, temp_data, FFT_FLAG, SCALE_FLAG);
//		data_selection = hwafft_512pts(bitrev_data, temp_data, FFT_FLAG, SCALE_FLAG);
	} else {
		data_selection = hwafft_256pts(bitrev_data, temp_data, FFT_FLAG, NOSCALE_FLAG);
//		data_selection = hwafft_512pts(bitrev_data, temp_data, FFT_FLAG, NOSCALE_FLAG);	
	}
	
	/* Return appropriate data pointer */
	if (data_selection) {
		fft_data = temp_data;
	} else {
		fft_data = bitrev_data;
	}
	
	/* Extract real and imaginary parts */
	for (i = 0; i < FFT_LENGTH; i++) {
		*(fft_real + i) = (Int16)((*(fft_data + i)) >> 16);
		*(fft_imag + i) = (Int16)((*(fft_data + i)) & 0x0000FFFF);
	}
		   	
}

/* ---------------- Wrapper function to implement HWAIFFT --------------- */
/* For more information see: Application Report - SPRABB6A, June 2010     */
/* Note that there are also several discussions in e2e.ti.com forums.     */
/* The appropriate functions are linked via c5515.cmd. See also:          */
/* http://e2e.ti.com/support/dsp/c5000/f/109/p/49635/176118.aspx#176118   */
/*																		  */
/* The function requires pre-allocated arrays for output data (16-bit Q15)*/
/* of the IFFT.							                                  */
/* ---------------------------------------------------------------------- */
void do_ifft(Int16 *fft_real, Int16 *fft_imag, Int16 *ifft_data, Uint16 scale)
{
	Uint16 i, data_selection;
	Int32 *complex_data, *bitrev_data, *temp_data, *ifft_tmp;
	
	/* Initialize relevant pointers */
	complex_data = complex_buffer;
	bitrev_data  = bitreversed_buffer;
	temp_data    = temporary_buffer;

	/* Reconstruct complex data from real and imaginary parts */
	for (i = 0; i < FFT_LENGTH; i++) {
		*(complex_data + i) = ((Int32)(*(fft_real + i)) << 16);
		*(complex_data + i) = *(complex_data + i) | ((Int32)(*(fft_imag + i)) & 0x0000FFFF);
	}
	
	/* Perform bit-reversing */
	hwafft_br(complex_data, bitrev_data, FFT_LENGTH);
	
	/* Perform IFFT */
	if (scale) {
		data_selection = hwafft_256pts(bitrev_data, temp_data, IFFT_FLAG, SCALE_FLAG);
//		data_selection = hwafft_512pts(bitrev_data, temp_data, IFFT_FLAG, SCALE_FLAG);
	} else {
		data_selection = hwafft_256pts(bitrev_data, temp_data, IFFT_FLAG, NOSCALE_FLAG);
//		data_selection = hwafft_512pts(bitrev_data, temp_data, IFFT_FLAG, NOSCALE_FLAG);	
	}
	
	/* Return appropriate data pointer */
	if (data_selection) {
		ifft_tmp = temp_data;
	} else {
		ifft_tmp = bitrev_data;
	}
	
	/* Return real part of IFFT */
	for (i = 0; i < FFT_LENGTH; i++) {
		*(ifft_data + i) = (Int16)((*(ifft_tmp + i)) >> 16); 
	}   	
}

