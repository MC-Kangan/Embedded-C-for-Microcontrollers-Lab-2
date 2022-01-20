#pragma config FEXTOSC = HS     // External Oscillator mode Selection bits (HS (crystal oscillator) above 8 MHz; PFM set to high power)
#pragma config RSTOSC = EXTOSC_4PLL// Power-up default value for COSC bits (EXTOSC with 4x PLL, with EXTOSC operating per FEXTOSC bits)
#pragma config WDTE = OFF        // WDT operating mode (WDT enabled regardless of sleep)

#include <xc.h>
#include "LEDarray.h"

#define _XTAL_FREQ 64000000 //note intrinsic _delay function is 62.5ns at 64,000,000Hz  

void main(void) 
{
	// setup pin for input (connected to button1 - RF2)
    TRISFbits.TRISF2=1; //set TRIS value for pin (input)
    ANSELFbits.ANSELF2=0; //turn off analogue input on pin
    
    unsigned int count=0;
    LEDarray_init();
    
    while (1) {
        while (PORTFbits.RF2); // While the button is not pressed, trap in the loop
        if (!PORTFbits.RF2){ // If the button 1 is pressed, count+1
            ++count; // increment count 
            if (count >255) {count=0;} //Reset when count gets too large 255 = 0b11111111
            LEDarray_disp_bin(count); // Output a on the LED array in binary
        }
        
		__delay_ms(100); // Delay so human eye can see change. Increase to 100 to cleaner effect
    }
}
