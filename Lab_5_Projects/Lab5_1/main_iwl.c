#include "stdio.h"
#include "usbstk5515.h"
#include "intrindefs.h"

Int16 x[100];
Int16 y[100];

main(void)
{
    int i=0;
    int num=0;
    int temp=0;
    USBSTK5515_init( );

    for(i=4000;i<4100;i++)
    {
        x[i-4000]=i;
    }

/***************************************
*****Your conversion code goes here*****
***************************************/
    for(i=0;i<100;i++)
    {
      temp=x[i];
      num=0;
      while(temp)
      {
          temp=temp/2;
          num++;
      }
      y[i]=x[i]<<(15-num);
    }
    // Your code should return, in y, the values in x, expressed such that
    // they occupy fully the available 16 bit range provided by the datatype
    // Int16.

    return 0;
}

