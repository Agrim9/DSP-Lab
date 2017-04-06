 /*
 *  This file is written using examples provided by Spectrum Digital 
 */


//#include "stdio.h"
#include <stdio.h>
#include "usbstk5515.h"
#include "usbstk5515_gpio.h"
#include "usbstk5515_i2c.h"


#define AIC3204_I2C_ADDR 0x18
#define Rcv 0x08
#define Xmit 0x20

#ifndef TRUE
#define TRUE 1
#endif

#define freq_6_857 0xF1
#define freq_8 0xE1
#define freq_9_6 0xD1
#define freq_12 0xC1
#define freq_16 0xB1
#define freq_24 0xA1
#define freq_48 0x91
Int16 LEFT_DATA,RIGHT_DATA;
Int16 data_received[30]={0};

/* ------------------------------------------------------------------------ *
 *                                                                          *
 *  Initialization Functions                                                *
 *                                                                          *
 * ------------------------------------------------------------------------ */
Int16 AIC3204_rset( Uint16 regnum, Uint16 regval )
{
    Uint8 cmd[2];
    cmd[0] = regnum & 0x007F;       // 7-bit Register Address
    cmd[1] = regval;                // 8-bit Register Data

    return USBSTK5515_I2C_write( AIC3204_I2C_ADDR, cmd, 2 );
} 

void AIC3204_config(Uint8 sampling_freq)
{
	/* Configure AIC3204 */
     AIC3204_rset( 0, 0 );          // Select page 0
    AIC3204_rset( 1, 1 );          // Reset codec
    AIC3204_rset( 0, 1 );          // Select page 1
    AIC3204_rset( 1, 8 );          // Disable crude AVDD generation from DVDD
    AIC3204_rset( 2, 1 );          // Enable Analog Blocks, use LDO power
    AIC3204_rset( 0, 0 );          // Select page 0
    /* PLL and Clocks config and Power Up  */
    AIC3204_rset( 27, 0x0d );      // BCLK and WCLK is set as o/p to AIC3204(Master)
    AIC3204_rset( 28, 0x00 );      // Data ofset = 0
    AIC3204_rset( 4, 3 );          // PLL setting: PLLCLK <- MCLK, CODEC_CLKIN <-PLL CLK
    AIC3204_rset( 6, 7 );          // PLL setting: J=7
    AIC3204_rset( 7, 0x06 );       // PLL setting: HI_BYTE(D=1680)
    AIC3204_rset( 8, 0x90 );       // PLL setting: LO_BYTE(D=1680)
    AIC3204_rset( 30, 0x88 );      // For 32 bit clocks per frame in Master mode ONLY
                                   // BCLK=DAC_CLK/N =(12288000/8) = 1.536MHz = 32*fs
    AIC3204_rset( 5, sampling_freq);       // PLL setting: Power up PLL, P=1 and R=1
    AIC3204_rset( 13, 0 );         // Hi_Byte(DOSR) for DOSR = 128 decimal or 0x0080 DAC oversamppling
    AIC3204_rset( 14, 0x80 );      // Lo_Byte(DOSR) for DOSR = 128 decimal or 0x0080
    AIC3204_rset( 20, 0x80 );      // AOSR for AOSR = 128 decimal or 0x0080 for decimation filters 1 to 6
    AIC3204_rset( 11, 0x82 );      // Power up NDAC and set NDAC value to 2
    AIC3204_rset( 12, 0x87 );      // Power up MDAC and set MDAC value to 7
    AIC3204_rset( 18, 0x87 );      // Power up NADC and set NADC value to 7
    AIC3204_rset( 19, 0x82 );      // Power up MADC and set MADC value to 2
    /* DAC ROUTING and Power Up */
    AIC3204_rset(  0, 0x01 );      // Select page 1
    AIC3204_rset( 12, 0x08 );      // LDAC AFIR routed to HPL
    AIC3204_rset( 13, 0x08 );      // RDAC AFIR routed to HPR
    AIC3204_rset(  0, 0x00 );      // Select page 0
    AIC3204_rset( 64, 0x02 );      // Left vol=right vol
    AIC3204_rset( 65, 0x00 );      // Left DAC gain to 0dB VOL; Right tracks Left
    AIC3204_rset( 63, 0xd4 );      // Power up left,right data paths and set channel
    AIC3204_rset(  0, 0x01 );      // Select page 1
    AIC3204_rset( 16, 0x00 );      // Unmute HPL , 0dB gain
    AIC3204_rset( 17, 0x00 );      // Unmute HPR , 0dB gain
    AIC3204_rset(  9, 0x30 );      // Power up HPL,HPR
    AIC3204_rset(  0, 0x00 );      // Select page 0
    USBSTK5515_wait( 500 );        // Wait
    
    /* ADC ROUTING and Power Up */
    AIC3204_rset( 0, 1 );          // Select page 1
    AIC3204_rset( 0x34, 0x30 );    // STEREO 1 Jack
		                           // IN2_L to LADC_P through 40 kohm
    AIC3204_rset( 0x37, 0x30 );    // IN2_R to RADC_P through 40 kohmm
    AIC3204_rset( 0x36, 3 );       // CM_1 (common mode) to LADC_M through 40 kohm
    AIC3204_rset( 0x39, 0xc0 );    // CM_1 (common mode) to RADC_M through 40 kohm
    AIC3204_rset( 0x3b, 0 );       // MIC_PGA_L unmute
    AIC3204_rset( 0x3c, 0 );       // MIC_PGA_R unmute
    AIC3204_rset( 0, 0 );          // Select page 0
    AIC3204_rset( 0x51, 0xc0 );    // Powerup Left and Right ADC
    AIC3204_rset( 0x52, 0 );       // Unmute Left and Right ADC
    
    AIC3204_rset( 0, 0 );    
    USBSTK5515_wait( 200 );        // Wait
    /* I2S settings */
    I2S0_SRGR = 0x0;
    I2S0_CR = 0x8010;    // 16-bit word, slave, enable I2C
    I2S0_ICMR = 0x3f;    // Enable interrupts
    
}
/* ------------------------------------------------------------------------ *
 *                                                                          *
 *  Function to detect one                                                  *
 *                                                                          *
 * ------------------------------------------------------------------------ */ 
 Int16 detect_one()
{
    Int16 count_of_one = 0; 
    Int16 data_count = 1; 
     
    while(TRUE)
    {
    while((Rcv & I2S0_IR) == 0);  // Wait for interrupt pending flag
	LEFT_DATA = I2S0_W0_MSW_R;  // 16 bit left channel received audio data
	RIGHT_DATA = I2S0_W1_MSW_R;  // 16 bit right channel received audio data
	
	data_count = data_count + 1; 
	
	//These values of data_count correspond to the mid values of peaks of RZ waveforms
	//The original waveform was of 96 samples, hence its peak was in the first 48 samples	
	//48/2=24 , 24 + 96 = 120, ...
	if( data_count == 24 || data_count == 120 || data_count == 216 || data_count == 312 || data_count == 408 || data_count == 504) 
	{ 
		if( LEFT_DATA > 4500 )
		{
			count_of_one = count_of_one + 1; 
		}	
	}
	
	if( data_count > 504 && LEFT_DATA < 500 )//break out of loop to enable to detect the new bit 
	{  
    	break;
	}
    }
	return count_of_one;
}
/* ------------------------------------------------------------------------ *
 *                                                                          *
 *  Function to detect zero                                                 *
 *                                                                          *
 * ------------------------------------------------------------------------ */
Int16 detect_zero()
{ 
    /*
	(checkpoint)
	similar to the one above, write your own code to detect a zero
    */
    
    Int16 count_of_zero = 0; 
    Int16 data_count = 1; 
     
    while(TRUE)
    {
    while((Rcv & I2S0_IR) == 0);  // Wait for interrupt pending flag
	LEFT_DATA = I2S0_W0_MSW_R;  // 16 bit left channel received audio data
	RIGHT_DATA = I2S0_W1_MSW_R;  // 16 bit right channel received audio data
	
	data_count = data_count + 1; 
	
	//These values of data_count correspond to the mid values of peaks of RZ waveforms
	//The original waveform was of 192 samples, hence its peak was in the first 48 samples	
	//48/2=24 , 24 + 96 = 120, ...
	if( data_count == 48 || data_count == 240 || data_count == 432 || data_count == 624 || data_count == 816 || data_count == 1008 )
	{ 
		if( LEFT_DATA < -4500 )
		{
			count_of_zero = count_of_zero + 1; 
		}	
	}
	
	if( data_count > 1008 && LEFT_DATA > -500 )//break out of loop to enable to detect the new bit 
	{  
    	break;
	}
    }
	return count_of_zero;
}
 
/* ------------------------------------------------------------------------ *
 *                                                                          *
 *  main( )                                                                 *
 *                                                                          *
 * ------------------------------------------------------------------------ */ 
 main( void )
{ 
    Int16 i=0,x=0;
    Int16 j=0;
    Int16 p;
    Int16 count=0;
    /* Initialize BSL */      
    SYS_EXBUSSEL = 0x6100; 
    USBSTK5515_init( );
    AIC3204_config(freq_48);
    
    //here we are initializing the buffer values to make it easier to debug
    for(j=0; j<30; j++)
    {
    	data_received[j] = 5;
    }
    	
    while(TRUE)
    {
	    while((Rcv & I2S0_IR) == 0);  // Wait for interrupt pending flag
	    LEFT_DATA = I2S0_W0_MSW_R;  // 16 bit left channel received audio data
	    RIGHT_DATA = I2S0_W1_MSW_R;  // 16 bit right channel received audio data
	     
	    if( LEFT_DATA > 3000 ) // Setting thresholds
	    {
	    	count = detect_one();
	    	if( count > 3 )
	    	{
	    		data_received[i] = 0; // Since the board has an inverter at its output, hence we detect 0 and not 1 here.
	    		//printf("%d", data_received[i]);
	    		i = i + 1; 
	    		if( i == 30 )
	    		{
	    		i=0;	
	    		break;
	    		} 
	    	}	 
	    	//printf(" Bit received at %d is %d \n", i, data_received[i]);
	    }
	    
	    if( LEFT_DATA < -3000 )  // Setting thresholds
	    {
	    	count = detect_zero(); 
	    	if( count > 3 )
	    	{
	    		data_received[i] = 1; // Since the board has an inverter at its output, hence we detect 1 and not 0 here.
	    		//printf("%d", data_received[i]);
	    		i = i + 1; 
	    		if( i == 30 )
	    		{
	    		i=0;	
	    		break;
	    		} 
	    	}
	    	//printf(" Bit received at %d is %d \n", i, data_received[i]);
	    } 
	    	   		    
    }   

    //Extract the data received(checkpoint)
    /*
	Now that the data has been received in the data_received buffer, extract the data and print it in console
    */ 		
    for (i=0;i<30;i++)
    {
       if(data_received[i]==1 && data_received[i+1]==1 && data_received[i+2]==0 && data_received[i+3]==1 && data_received[i+4]==0)
                {
                    printf("Preamble Detected, Breaking ....\n");
                    break;
                }

     }

     for(x=i+5;x<(i+11);x++)
     {
         printf("Data Recvd %d\n", data_received[x]);
     }

    /* Disble I2S */    
    I2S0_CR = 0x00;
    return 0;
}
