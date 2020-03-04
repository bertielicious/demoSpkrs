#include "config.h"
#include "byteToBin.h"
void splashScreen(void)
{
    uchar splash[] = {"CI Speaker demo"};
    
    uchar *chickPtr = &splash[0];
   
    byteToBin(0,0x81); 
    
    while (*chickPtr > 0)
    {
        byteToBin(1, *chickPtr);    // send charater data to the LCD
        chickPtr++;
    }
   
}

