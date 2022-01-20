#pragma config FEXTOSC = HS     // External Oscillator mode Selection bits (HS (crystal oscillator) above 8 MHz; PFM set to high power)
#pragma config RSTOSC = EXTOSC_4PLL// Power-up default value for COSC bits (EXTOSC with 4x PLL, with EXTOSC operating per FEXTOSC bits)
#pragma config WDTE = OFF        // WDT operating mode (WDT enabled regardless of sleep)

#include <xc.h>
#include "LEDarray.h"

#define _XTAL_FREQ 64000000 //note intrinsic _delay function is 62.5ns at 64,000,000Hz  

void main(void) 
{
	unsigned int count=0;
    LEDarray_init();
    int arr[] = { 0,1,2,4,8,16,32,64,128,64,32,16,8,4,2,1 };//create an array that contains the number that could lit up the LED
    while (1) {
		count++; // increment count 
        // Calculate length of the array (Number of elements): length of array =  size of array / size of any one element
        int Length  = sizeof(arr)/sizeof(arr[0]);
		if (count >Length-1) {count=0;} //Reset when count > the length of the array; Length - 1 cuz it counts from 0
        LEDarray_disp_bin(arr[count]); // Output a on the LED array in binary
        
		__delay_ms(50); // Delay so human eye can see change
    }
}
