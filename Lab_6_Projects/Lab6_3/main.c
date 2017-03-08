#include "data_types.h"
#include "hwafft.h"
#include "stdio.h"

#define FFT_LENGTH 8

void USBSTK5515_init(void);


Int16 x[FFT_LENGTH]={1,0,2,0,3,0,4,0};
float x_sw[FFT_LENGTH], y_sw_real[FFT_LENGTH], y_sw_imag[FFT_LENGTH];

///* --- Special buffers required for HWAFFT ---*/
#pragma DATA_SECTION(complex_buffer, "cmplxBuf");
Int32 complex_buffer[FFT_LENGTH];

#pragma DATA_SECTION(bitreversed_buffer, "brBuf");
#pragma DATA_ALIGN(bitreversed_buffer, 2*FFT_LENGTH);
Int32 bitreversed_buffer[FFT_LENGTH];

#pragma DATA_SECTION(temporary_buffer,"tmpBuf");
Int32 temporary_buffer[FFT_LENGTH];
/* -------------------------------------------*/

void do_fft(Int16 *real_data, Int16 *fft_real, Int16 *fft_imag, Uint16 scale);
void do_ifft(Int16 *fft_real, Int16 *fft_imag, Int16 *ifft_data, Uint16 scale);
Int16 realpart_fft[8],imagpart_fft[8],scale=0;
float y_real[8],y_imag[8];

// int bitrev_of(int dec)
// Takes in a value between 0 and 7 and returns its bit-reversed form.
// For ex. bitrev_of(3)=6.
int bitrev_of(int dec)
{
    int units_place_bin,tens_place_bin,hund_place_bin;
    units_place_bin=dec%2;
    tens_place_bin=(dec/2)%2;
    hund_place_bin=(dec/4)%2;
    return 4*units_place_bin+2*tens_place_bin+hund_place_bin;
}

// void complex_multiply(float* ip1_real, float* ip1_imag, float* ip2_real, float* ip2_imag, float* res_real, float* res_imag)
// Computes the product of 2 complex numbers.
// ip1_real and ip1_imag are POINTERS to the real and imaginary parts of 1st operand
// ip2_real and ip2_imag are POINTERS to the real and imaginary parts of 2nd operand
// res_real and res_imag are POINTERS to the real and imaginary parts of the product of the 2 complex numbers.
void complex_multiply(float* ip1_real, float* ip1_imag, float* ip2_real, float* ip2_imag, float* res_real, float* res_imag)
{
    float temp1,temp2;
    temp1 = (*ip1_real) * (*ip2_real) - (*ip1_imag) * (*ip2_imag);
    temp2 = (*ip1_real) * (*ip2_imag) + (*ip1_imag) * (*ip2_real);
    *res_real = temp1;
    *res_imag = temp2;
}

// void butterfly(float*x0_real, float*x0_imag, float*x1_real, float*x1_imag, float*y0_real, float*y0_imag, float*y1_real, float*y1_imag)
// x0_real and x0_imag are the POINTERS to the real and imaginary parts of 1st operand
// x1_real and x1_imag are the POINTERS to the real and imaginary parts of 2nd operand
// y0_real and y0_imag are the POINTERS to the real and imaginary parts of 1st output
// y1_real and y1_imag are the POINTERS to the real and imaginary parts of 2nd output
void butterfly(float*x0_real, float*x0_imag, float*x1_real, float*x1_imag, float*y0_real, float*y0_imag, float*y1_real, float*y1_imag)
{
    *y0_real = *x0_real + *x1_real;
    *y0_imag = *x0_imag + *x1_imag;
    *y1_real = *x0_real - *x1_real;
    *y1_imag = *x0_imag - *x1_imag;
}
void sw_fft(float* x, float* y_real, float* y_imag)
{   int i1=0,j1=0;
    int i=0,j=0;
    float dummy_imag=0;
    float twiddle_real[8]={1,0.7071,0,-0.7071,-1,-0.7071,0,0.7071};// twiddle_real[k]=cos((2pi/8)*k) ; 0<=k<=7
    float twiddle_imag[8]={0,-0.7071,-1,-0.7071,0,0.7071,1,0.7071};// twiddle_imag[k]=-sin((2pi/8)*k); 0<=k<=7
    float x_bitrev_real[8],x_bitrev_imag[8],stage_1_real[8],stage_1_imag[8],stage_2_real[8],stage_2_imag[8];

    // Calculate the bit-reversed form of x in x_bitrev.
    for(i=0;i<8;i++)
    {
        x_bitrev_real[i]=x[bitrev_of(i)];
        x_bitrev_imag[i]=0;
    }

/*
    You can pass the POINTER of a variable to a function by preceding its name with an "&".
    For ex. void foo(float* input, float* output) can be called as foo(&myinput,&myoutput) if myinput and myoutput are float variables.
    Function "foo" will process the value whose address is stored in "input", store the output in a variable and return its address in "myoutput".
*/

    // Calculate the stage 1 values with the help of butterfly() function.
    // You can omit the "multiplication by twiddle factor" stage here as all of them are 1.
    for(i=0;i<4;i++)
    {
        butterfly(&x_bitrev_real[2*i],&x_bitrev_imag[2*i],&x_bitrev_real[2*i+1],&x_bitrev_imag[2*i+1],&stage_1_real[2*i],&stage_1_imag[2*i],&stage_1_real[2*i+1],&stage_1_imag[2*i+1]);
        /*Your Code Goes here*/

    }

    // Calculate the stage 2 values from stage 1 values with the help of complex_multiply() and butterfly() functions.
    for(i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
        {
            i1=i+4*j;
            j1=i1+2;
            // Multiply selected values in stage 1 by the twiddle factors before calculating the butterfly.
            complex_multiply(&stage_1_real[j1],&stage_1_imag[j1],&twiddle_real[2*i],&twiddle_imag[2*i],&stage_1_real[j1],&stage_1_imag[j1]);
                /*Your Code Goes here*/

            // Butterfly calculation
            butterfly(&stage_1_real[i1],&stage_1_imag[i1],&stage_1_real[j1],&stage_1_imag[j1],&stage_2_real[i1],&stage_2_imag[i1],&stage_2_real[j1],&stage_2_imag[j1]);
                /*Your Code Goes here*/

        }
    }

    // Calculate the output values from stage 2 values with the help of complex_multiply() and butterfly() functions.
    for(i=0;i<4;i++)
    {
        // Multiply selected values in stage 2 by the twiddle factors appropriately before calculating the butterfly.
        complex_multiply(&stage_2_real[i+4],&stage_2_imag[i+4],&twiddle_real[i],&twiddle_imag[i],&stage_2_real[i+4],&stage_2_imag[i+4]);

            /*Your Code Goes here*/

        // Butterfly calculation (Note that y_real and y_imag themselves are POINTERS)
        butterfly(&stage_2_real[i],&stage_2_imag[i],&stage_2_real[i+4],&stage_2_imag[i+4],&y_real[i],&y_imag[i],&y_real[i+4],&y_imag[i+4]);

            /*Your Code Goes here*/

    }
}
int main(void)
{
    int i=0;
	//USBSTK5515_init();
    for(i=0;i<10;i++)
	do_fft(x, realpart_fft, imagpart_fft, scale);
	
	//Profile only 1 function at a time
	//for(i=0;i<10;i++)
    //sw_fft(x_sw, y_sw_real, y_sw_imag);
		 
	return 0;
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
//		data_selection = hwafft_128pts(bitrev_data, temp_data, FFT_FLAG, SCALE_FLAG);
		data_selection = hwafft_8pts(bitrev_data, temp_data, FFT_FLAG, SCALE_FLAG);
	} else {
//		data_selection = hwafft_128pts(bitrev_data, temp_data, FFT_FLAG, NOSCALE_FLAG);
		data_selection = hwafft_8pts(bitrev_data, temp_data, FFT_FLAG, NOSCALE_FLAG);	
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
//		data_selection = hwafft_128pts(bitrev_data, temp_data, IFFT_FLAG, SCALE_FLAG);
		data_selection = hwafft_512pts(bitrev_data, temp_data, IFFT_FLAG, SCALE_FLAG);
	} else {
//		data_selection = hwafft_128pts(bitrev_data, temp_data, IFFT_FLAG, NOSCALE_FLAG);
		data_selection = hwafft_512pts(bitrev_data, temp_data, IFFT_FLAG, NOSCALE_FLAG);	
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

