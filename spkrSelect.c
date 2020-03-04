#include "config.h"
#include "stdio.h"
#include "byteToBin.h"
#include "clearLCD.h"
void spkrSelect(uchar *event, uchar *prevEvent ,uchar *numSpkrz)
{
    const uchar rotate[]={"rotate"};
    const uchar press[]={"press"};
    const uchar rotateOrPress[]={"rotate or press"};
    const uchar numb[]={"number of pairs "};
    const uchar numb2[]={"of demo spkrs?"};
    const uchar select1[]={"sel spkr to play"};
    const uchar playspksA[]={"play speakers A? "};
    const uchar rotateSpkrs[]={"rotate speakers "};
    const uchar muted[]={"speakers muted "};
    const uchar activeA[]={"spkrs A playing "};
    uchar *ptrNumb;
    uchar *ptr;
    switch(*event)
    {
        case 2:
            if(SW==HIGH)
            {
                
                ptrNumb = &numb[0];
                byteToBin(0,0x80);// print to 1st line LCD "number of pairs"
                while(*ptrNumb > 0)
                {
                    byteToBin(1, *ptrNumb);
                    ptrNumb++;
                }
                ptrNumb = &numb2[0];
                byteToBin(0,0xc0);// print to 2nd line LCD "of demo spkrs?"
                while(*ptrNumb > 0)
                {
                    byteToBin(1, *ptrNumb);
                    ptrNumb++;
                }
                byteToBin(0,0xcf);      // display 1-3 via rotary encoder on line 2
                byteToBin(1, (0x30+(count%3)+1));
            }  
            if(SW==LOW)
            {
                *event = 3;
            }
        break;   
        case 3:
            while(SW==LOW);
            {
                *numSpkrz = (count%3) + 1; 
                clearLCD();
                *event = 4;
                printf("numSpkrz =    %d\n", *numSpkrz);
                while(SW==LOW); // wait SW to be released
            }
            break;
        case 4: 
                CWflag = LOW;
                ACWflag = LOW;
                *prevEvent = 3;
                ptrNumb = &select1[0];
                byteToBin(0,0x80);// print to 1st line LCD 
                while(*ptrNumb > 0)
                {
                    byteToBin(1, *ptrNumb);
                    ptrNumb++;
                }
                
                if(SW==LOW && *prevEvent==3)
                {
                    *prevEvent = 4;
                    *event = 5;                  
                }
                if(CWflag==HIGH)
                {
                    *event = 11;
                }
               
                break;
              
        case 5:
          
            
            while(SW==LOW);     // wait for SW to be released
                RL1 = LOW;      // deactivate all loudspeakers
                RL2 = LOW;
                RL3 = LOW;
            
                ptrNumb = &playspksA[0];
                byteToBin(0,0x80);// print to 1st line LCD 
            
                while(*ptrNumb > 0)
                {   
                    byteToBin(1, *ptrNumb);
                    ptrNumb++;
                }
             
                if(SW==LOW && *prevEvent==4)
                {
                    *event = 6;
                }   
                else if(SW==LOW && *prevEvent==6)
                {
                    *event = 4;
                }   
            break;
            
        case 6:
           
            ptrNumb = &activeA[0];
                byteToBin(0,0x80);// print to 2nd line LCD 
            
                while(*ptrNumb > 0)
                {   
                    byteToBin(1, *ptrNumb);
                    ptrNumb++;
                }

             RL1 = HIGH;        // activate speakers A
            
             while(SW==LOW);
             while(SW==HIGH);     // wait for SW to be released
             *prevEvent = 6;
             *event = 5;
             break;
            
        case 11:
          
            
            ptrNumb = &rotateSpkrs[0];
            byteToBin(0,0x80);// print to 1st line LCD 
                while(*ptrNumb > 0)
                {
                    byteToBin(1, *ptrNumb);
                    ptrNumb++;
                }
            while(ACWflag==LOW);
            if(SW==HIGH && ACWflag==HIGH)
            {
                *event = 4;
            }
            break;
           
    }
     
    printf("%d\n", *event)    ;
}
