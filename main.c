/************************************
 * Configuring registers before beginning
************************************/
#pragma config FEXTOSC = HS
#pragma config RSTOSC = EXTOSC_4PLL 
#pragma config WDTE = OFF        

/************************************
 * List containing pin names for the PIC chip, and maps code to correct locations
 ************************************/
#include <xc.h>

/************************************
 * Sets the chip oscillator speed
 ************************************/
#define _XTAL_FREQ 64000000 

/************************************
/ main function
 * Toggle lights on and off based on button inputs
************************************/
void main(void) {    
    // setup pin for output (connected to LED)
    LATDbits.LATD7=0;   //set initial output state
    TRISDbits.TRISD7=0; //set TRIS value for pin (output)
    
    LATHbits.LATH3=0;   //set initial output state
    TRISHbits.TRISH3=0; //set TRIS value for pin (output)
    
    // setup pin for input (connected to button)
    TRISFbits.TRISF2=1; //set TRIS value for pin (input) BUTTON 1
    ANSELFbits.ANSELF2=0; //turn off analogue input on pin 
    
    TRISFbits.TRISF3=1; //set TRIS value for pin (input) BUTTON 2
    ANSELFbits.ANSELF3=0; //turn off analogue input on pin
    
    while (1) { //infinite while loop - repeat forever
        
        if (!PORTFbits.RF2) 
        {
            LATDbits.LATD7 = !LATDbits.LATD7; //toggle LED
        }
        
        if (!PORTFbits.RF3)
        {
            LATHbits.LATH3 = !LATHbits.LATH3;
        }
            
        __delay_ms(200); // call built in delay function 
    }
}