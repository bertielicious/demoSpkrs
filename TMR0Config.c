#include "config.h"
void TMR0Config(void)
{
    OPTION_REGbits.T0CS = LOW;    // counter mode
    OPTION_REGbits.PSA = LOW;
    OPTION_REGbits.PS2 = HIGH;
    OPTION_REGbits.PS1 = HIGH;
    OPTION_REGbits.PS0 = HIGH;
    TMR0 = 0xf0;
    INTCONbits.GIE = HIGH;
    INTCONbits.T0IE = HIGH;
    INTCONbits.T0IF = LOW;   
}
