#include <xc.h>
#include "ADC.h"
#include "SENSOR_IR.h"
#include <math.h>
#include "UART.h"

//OSCILLATOR SOURCE AND DIGITAL I/O CONFIGURATION BITS
#pragma config OSC = IRCIO67    // Oscillator Selection bits (Internal oscillator block, port function on RA6 and RA7)
#pragma config MCLRE = ON       // MCLR Pin Enable bit (MCLR pin enabled; RE3 input pin disabled)
#pragma config PBADEN = OFF     // PORTB A/D Enable bit (PORTB<4:0> pins are configured as digital I/O on Reset)
#pragma config LVP = OFF        // Single-Supply ICSP Enable bit (Single-Supply ICSP disabled)

//DEBUGGER SETUP CONFIGURATION BITS
#pragma config WDT = OFF        // Watchdog Timer Enable bit (WDT disabled (control is placed on the SWDTEN bit))

void main(void) {

    OSCCON = 0X60; //4 MHz internal oscillator

    TRISAbits.RA0 = 1;
    TRISD = 0x00;
    INIT_UART();


    INIT_ADC(1, 0, 10);

    READPORT(0);

    while (1) {

        ADC_PROCESS();

        unsigned char Distancia_cm = DISTANCIA();

        SEND_UART(Distancia_cm);
        
        __delay_ms(1000);
    }
    return;
}