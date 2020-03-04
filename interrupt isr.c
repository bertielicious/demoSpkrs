#include "config.h"
#include "encDebounce.h"
#include "byteToBin.h"
#include "nibToBin.h"
#include "scrollLCD.h"

void interrupt isr(void)
{
    if(INTCONbits.T0IF == HIGH)
    {
        encDebounce();
        
        //LED = ~LED;
      /* sum++;
        if(sum >250)
           
        { 
           nibToBin(LOW,0x01);
         nibToBin(LOW,0x08); 
         byteToBin(0,0xc0);
         byteToBin(1, 0x30+(count/10));
         byteToBin(0,0xc1);
         byteToBin(1, 0x30+(count%10));
            sum = 0;
        }*/
    }
    TMR0 = 0xf0;
    INTCONbits.T0IF = LOW; 
}
 