#include "config.h"
#include "byteToBin.h"
void clearLCD(void)
{
    byteToBin(1,0x20);      // send 'space' character as data
    byteToBin(0,0x01);      // send 0x01 as instruction (address))    
}
