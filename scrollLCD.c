#include "config.h"
#include "nibToBin.h"
void scrollLCD(uchar direction)
{  
         nibToBin(LOW,0x01);
         nibToBin(LOW,direction);
}
