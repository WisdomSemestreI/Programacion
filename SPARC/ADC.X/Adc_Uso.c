#include <xc.h>
#include "ADC.h"

//OSCILLATOR SOURCE AND DIGITAL I/O CONFIGURATION BITS
#pragma config OSC = IRCIO67    // Oscillator Selection bits (Internal oscillator block, port function on RA6 and RA7)
#pragma config MCLRE = ON       // MCLR Pin Enable bit (MCLR pin enabled; RE3 input pin disabled)
#pragma config PBADEN = OFF     // PORTB A/D Enable bit (PORTB<4:0> pins are configured as digital I/O on Reset)
#pragma config LVP = OFF        // Single-Supply ICSP Enable bit (Single-Supply ICSP disabled)

//DEBUGGER SETUP CONFIGURATION BITS
#pragma config WDT = OFF        // Watchdog Timer Enable bit (WDT disabled (control is placed on the SWDTEN bit))


void main(void) {
    
    TRISAbits.RA0 = 1;
    TRISC = 0x00;
    
    ActAN0();
    NoVref();
    SelAN0();
    RightJust();
    TACQ_16TAD();
    ConvClk4();  
    while(1){  
    EnADC();
    CONVERT_A_D();
    PORTC = LSB;
    }
    return;
}
