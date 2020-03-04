#include "config.h"
void portDir(void)
{
     /* turn off adc module and comparators*/
    ANSEL = 0x00;
    ANSELH = 0x00;  // ADC module off
    CM1CON0 = 0x00;
    CM2CON0 = 0x00; // comparators off
    CM2CON1 = 0x00;
    TRISCbits.TRISC0 = LOW;     // RS   RC0 16
    TRISCbits.TRISC1 = LOW;     // EN   RC1 15
    TRISCbits.TRISC2 = LOW;     // D7   RC2 14
    TRISCbits.TRISC3 = LOW;     // D6   RC3 7
    TRISCbits.TRISC4 = LOW;     // D5   RC4 6
    TRISCbits.TRISC5 = LOW;     // D4   RC5 5
    TRISAbits.TRISA2 = LOW;     // RL1  RA2 17
    TRISAbits.TRISA5 = HIGH;    // SW   RA5 2
    TRISCbits.TRISC6 = HIGH;    // DT   RC6 8
    TRISCbits.TRISC7 = HIGH;    // CLK  RC7 9
    TRISBbits.TRISB6 = LOW;     // RL2  RB6 11
    TRISBbits.TRISB4 = LOW;     // RL3  RB4 13  
}
