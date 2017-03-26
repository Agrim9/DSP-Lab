
// ****************************************************************
// Description: This application uses Probe Points to obtain input
// (a sine wave). It then takes this signal, and applies a gain
// factor to it.
// Filename: sine_checkpoint.c
// ****************************************************************

#include <stdio.h>
#include <math.h>
#include "sine.h"
#include "usbstk5515.h"

// Define some functions 
static void modulate();
static void demodulate();            // process the input and generate output 
 void dataInput();             // dummy function to be used with ProbePoint
 void dataOutput();            // dummy function to be used with ProbePoint

Int16 input[BUFFSIZE];
Int16 output[BUFFSIZE];
Int16 wave[BUFFSIZE];
Int16 temp =0;

Int16 bit_transmitted[N_cycle]={1,1,0,0,1,1,0,0,1,1,0,0,1,1,0};
Int16 bit_received[N_cycle];

void main()
{
	int i;

  
    for(i=0;i<BUFFSIZE;i++)
    {
    	// Your reference signal generation goes here
        wave[i]=20*cos(2*3.14*Wc*i*delta_T);
    }
     
    
      
    while(1) // loop forever
    {
    	
    	
    	
    	     
        /*  Read input data using a probe-point connected to a host file. */
       //dataInput();
       
       modulate();
       
       /* Apply the gain to the input to obtain the output */
       demodulate();

       /*  Write output data to a graph connected through a probe-point. */
       //dataOutput();
    }
}



void modulate()
{
    // Your modulation code goes here
    int i=0,j=0;

    for(i=0;i<N_cycle;i++)
    {
        if(bit_transmitted[i]==1)
        {

            for(j=0;j<21;j++)
            {
                output[21*i+j]=wave[21*i+j];
            }
        }
        else
        {
            for(j=0;j<21;j++)
            {
                output[21*i+j]=-wave[21*i+j];
            }
        }
    }

}

void demodulate()
{
    // Your demodulation code goes here
    int i=0,j=0;
    float inn_pro=0;
    for(i=0;i<N_cycle;i++)
    {
        //Inner Product
        inn_pro=0;
        for(j=0;j<21;j++)
        {
            inn_pro+=(wave[21*i+j]*output[21*i+j]);
        }
        if(inn_pro>0)
        {
            bit_received[i]=1;
        }
        else
        {
            bit_received[i]=0;
        }
    }
}




