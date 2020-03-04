#include "config.h"
#include <stdio.h>
void encDebounce(void)
{                                          
    switch(state)
    {
        case 1:
            if(DT==1 && CLK==0)
            {
                state = 2;
                ACWflag = 0;
            }
            else if(DT==0 && CLK==1)
            {
                state = 5;
                CWflag = 0;
            }
            else if(DT==1 && CLK==1)
            {
                state = 1;
                
            }
            break;
        case 2:
            if(DT==0 && CLK==0)
            {
                state = 3;
            }
            else if(DT==1 && CLK==0)
            {
                state = 2;
            }
             break;
        case 3:
            if(DT==0 && CLK==1)
            {
                state = 4;
            }
            else if(DT==0 && CLK==0)
            {
                state = 3;
            }
             break;
        case 4:
            if(DT==1 && CLK==1)
            {
                if(count < 99)
                {
                    count++;
                }
                CWflag = 1;
                state = 1;
            }
            else if(DT==0 && CLK==1)
            {
                state = 4;
            }
             break;
         case 5:
            if(DT==0 && CLK==0)
            {
                state = 6;
            }
            else if(DT==0 && CLK==1)
            {
                state = 5;
                
            }
             break;
        case 6:
            if(DT==1 && CLK==0)
            {
                state = 7;
            }
            else if(DT==0 && CLK==1)
            {
                state = 6;
            }
             break;
        case 7:
            if(DT==1 && CLK==1)
            {
                if(count > 0)
                {
                    count--;
                }
                ACWflag = 1;
                state = 1;
            }
            else if(DT==0 && CLK==0)
            {
                state = 6;
            }
             break;
        default: state = 1;
    }
}