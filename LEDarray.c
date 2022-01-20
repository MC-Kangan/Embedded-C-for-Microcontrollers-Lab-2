#include <xc.h>
#include "LEDarray.h"

/************************************
/ LEDarray_init
/ Function used to initialise pins to drive the LEDarray
************************************/
void LEDarray_init(void)
{   //set up TRIS registers for pins connected to LED array
    TRISGbits.TRISG0 = 0; //pin G0 set to output
    TRISGbits.TRISG1 = 0; //pin G1 set to output
    TRISAbits.TRISA2 = 0; //pin A2 set to output
    TRISFbits.TRISF6 = 0; //pin F6 set to output
    TRISAbits.TRISA4 = 0; //pin A4 set to output
    TRISAbits.TRISA5 = 0; //pin A5 set to output
    TRISFbits.TRISF0 = 0; //pin F0 set to output
    TRISBbits.TRISB0 = 0; //pin B0 set to output
    TRISBbits.TRISB1 = 0; //pin B1 set to output
    
	//set initial output LAT values (they may have random values when powered on)
    LATGbits.LATG0 = 1; // output of pin G0 set high
    LATGbits.LATG1 = 1; // output of pin G1 set high
    LATAbits.LATA2 = 1; // output of pin A2 set high
    LATFbits.LATF6 = 1; // output of pin F6 set high
    LATAbits.LATA4 = 1; // output of pin A4 set high
    LATAbits.LATA5 = 1; // output of pin A5 set high
    LATFbits.LATF0 = 1; // output of pin F0 set high
    LATBbits.LATB0 = 1; // output of pin B0 set high
    LATBbits.LATB1 = 1; // output of pin B1 set high
    
   
}

/************************************
/ LEDarray_disp_bin
/ Function used to display a number on the LED array in binary
************************************/
void LEDarray_disp_bin(unsigned int number)
{
	//some code to turn on/off the pins connected to the LED array
	//if statements and bit masks can be used to determine if a particular pin should be on/off
	//see Readme.md for examples
    
    // If the individual bit in number = the individual bit in the binary mask, return true, otherwise false.
    if (number & 0b00000000) { LATGbits.LATG0=1;} else { LATGbits.LATG0=0;} // 0b is the prefix for binary, number = 0
    if (number & 0b00000001) { LATGbits.LATG1=1;} else { LATGbits.LATG1=0;} // 0b is the prefix for binary, number = 1
    if (number & 0b00000010) { LATAbits.LATA2=1;} else { LATAbits.LATA2=0;} // 0b is the prefix for binary, number = 2
    if (number & 0b00000100) { LATFbits.LATF6=1;} else { LATFbits.LATF6=0;} // 0b is the prefix for binary, number = 4
    if (number & 0b00001000) { LATAbits.LATA4=1;} else { LATAbits.LATA4=0;} // 0b is the prefix for binary, number = 8
    if (number & 0b00010000) { LATAbits.LATA5=1;} else { LATAbits.LATA5=0;} // 0b is the prefix for binary, number = 16
    if (number & 0b00100000) { LATFbits.LATF0=1;} else { LATFbits.LATF0=0;} // 0b is the prefix for binary, number = 32
    if (number & 0b01000000) { LATBbits.LATB0=1;} else { LATBbits.LATB0=0;} // 0b is the prefix for binary, number = 64
    if (number & 0b10000000) { LATBbits.LATB1=1;} else { LATBbits.LATB1=0;} // 0b is the prefix for binary, number = 128

    
}

/************************************
/ Function LEDarray_disp_dec
/ Used to display a number on the LEDs
/ where each LED is a value of 10
************************************/
void LEDarray_disp_dec(unsigned int number)
{
	unsigned int disp_val;
	
	//some code to manipulate the variable number into the correct
	//format and store in disp_val for display on the LED array

	LEDarray_disp_bin(disp_val); 	//display value on LED array
}


/************************************
/ LEDarray_disp_PPM
/ Function used to display a level on the LED array with peak hold
/ cur_val is the current level from the most recent sample, and max is the peak value for the last second
/ these input values need to calculated else where in your code
************************************/
void LEDarray_disp_PPM(unsigned int cur_val, unsigned int max)
{
	unsigned int disp_val;
	
	// some code to format the variable cur_val and max, store in disp_val for display on the LED array
	// hint: one method is to manipulate the variables separately and then combine them using the bitwise OR operator

	LEDarray_disp_bin(disp_val);	//display value on LED array
}

