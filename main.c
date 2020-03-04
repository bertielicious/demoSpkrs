/* 12/02/20 don't use global variables, hide data within functions
 * Top level requirements description
 * This project is designed to allow the user to select one pair of speakers, 
 * to play from up to three available pairs. The speakers can be named by the user, 
 * and the details of the speaker should be displayed whilst it is playing. A
 * rotary encoder enables the user to scroll menu options and then select the 
 * desired option with the in-built push button. It should also be possible to
 * select a loudspeaker re-name option in case the speaker model is discontinued.
 * A final option is to cycle through all available speakers, playing each for 
 * a user definable time period from 10 to 60 sec.
 * 
 * Detailed design
 * The rotary encoder allows each menu option to be scrolled and selected 
 * (software de-bounce required).
 * Options are:
 * Name/ re-name speaker
 * Select speaker to play
 * Rotate playing of speakers every x seconds (10<x<60s)
 * The menu option highlighted in reverse video is selected by pressing the 
 * push botton of the rotary encoder (software de-bounce required).
 * 
 * The 4-bit interface LCD displays menu options 2 lines at a time, new options
 * scroll vertically.
 * Three two pole relays are under control from port C of the 16f690 uC. They
 * switch the incoming stereo audio signal to one pair of three pairs of 
 * speakers dependant upon the menu setting selected by the user.
 * 
 * If the power to the system is interrupted, the uC should remember the 
 * user inputted data (speaker names, last mode selected)
 * 
 * Pin allocations for the system to 16f690 uC
 *                  16f690
 *                  ---------
 *   +5 Volts    1 |Vdd      | 20 Vss 0V
 *     SW(ENC)   2 |RA5   RA0| 19   
 *               3 |RA4   RA1| 18   
 *    RESET      4 |RA3   RA2| 17  RL1 OUT
 *    LCD D4     5 |RC5   RC0| 16  RS
 *    LCD D5     6 |RC4   RC1| 15  EN
 *    LCD D6     7 |RC3   RC2| 14  LCD D7 
 *    DT(ENC)    8 |RC6   RB4| 13  RL3 OUT
 *    CLK(ENC)   9 |RC7   RB5| 12  
 *    TX        10 |RB7   RB6| 11  RL2 OUT
 *                  ---------
 */
#include "config.h"
#include<stdio.h>
#include "clock.h"
#include "portDir.h"
#include "nibToBin.h"
#include "byteToBin.h"
#include "pulse.h"
#include "configLCD.h"
#include "TMR0Config.h"
#include "configUsart.h"
#include "splashScreen.h"
#include "scrollLCD.h"
#include "putch.h"
#include "clearLCD.h"
#include "spkrSelect.h"
 int main(void)
 {
     uchar status = 2;
     uchar prevStatus = 2;
     uchar numSpkrs = 0;
     clock();
     portDir();
     configLCD();
     TMR0Config();
     configUsart(); 
     splashScreen();
     __delay_ms(1000);
     clearLCD();
     printf("Hello Phil !\n");
     
     

     while(1)
     {
         spkrSelect(&status, &prevStatus, &numSpkrs);// pass address of status and numSpkrs to function
       //  printf("CW %d\n",CWflag);
        // printf("ACW %d\n",ACWflag);
       //  printf("%d\n",status);     // so that when the value of status/ numSpkrs is captured in the function,
       //  printf("%d\n",numSpkrs);   //it is passed by reference, so that the value of status /numSpkrs is changed in main())
                                    // this avoids the use of a global variable status /numSpkrs and also allows the function to return
                                    // more than one value
       // nibToBin(LOW,0x01);                         // scrollLcd(0x08);
       // nibToBin(LOW,0x08);
       // __delay_ms(250);
        
        // byteToBin(0,0xc0);                         // print rotary encofer 0-99
        // byteToBin(1, 0x30+(count/10));
        // byteToBin(0,0xc1);
        // byteToBin(1, 0x30+(count%3));
         
     }
 }