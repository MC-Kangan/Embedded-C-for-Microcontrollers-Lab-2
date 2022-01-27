#pragma config FEXTOSC = HS     // External Oscillator mode Selection bits (HS (crystal oscillator) above 8 MHz; PFM set to high power)
#pragma config RSTOSC = EXTOSC_4PLL// Power-up default value for COSC bits (EXTOSC with 4x PLL, with EXTOSC operating per FEXTOSC bits)
#pragma config WDTE = OFF        // WDT operating mode (WDT enabled regardless of sleep)

#include <xc.h>
#include "LEDarray.h"
#include "ADC.h" // Include header file

#define _XTAL_FREQ 64000000 //note intrinsic _delay function is 62.5ns at 64,000,000Hz  

void main(void) 
{
	// setup pin for input (connected to button1 - RF2)
    TRISFbits.TRISF2=1; //set TRIS value for pin (input)
    ANSELFbits.ANSELF2=0; //turn off analogue input on pin
    
    unsigned int max=0;
    unsigned int cur_val=0;
    
    LEDarray_init(); // Defined in LEDarray.c
    ADC_init(); // Defined in ADC.c
       
    while (1) {
        cur_val = ADC_getval();  // get brightness in digital
        // If cur_val >= max, let cur_val be max
        
        // Note: Simplistic way of writing this code
        if (cur_val >= max){max = cur_val;} else {max -= 10;} // Subtract 10 every 1s in order to decrease 1 led every second
        LEDarray_disp_PPM(cur_val, max);
       
         __delay_ms(1000);}
        
        



}
