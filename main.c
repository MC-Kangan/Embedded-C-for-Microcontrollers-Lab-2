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
    
    unsigned int count=0;
    LEDarray_init(); // Defined in LEDarray.c
    ADC_init(); // Defined in ADC.c
    
    while (1) {
        LEDarray_disp_dec(ADC_getval()); // Output a on the LED array in binary
		__delay_ms(50); // Delay so human eye can see change. 
    }
}
