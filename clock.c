#include "config.h"

void clock(void)
{
    OSCCONbits.IRCF0 = HIGH;        // 8MHz clock, fosc/4 = 2MHz
    OSCCONbits.IRCF1 = HIGH;
    OSCCONbits.IRCF2 = HIGH;
    OSCCONbits.SCS = HIGH;          // internal oscillator used for system clock selected
}