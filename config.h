/* 
 * File:   config.h
 * Author: Phil Glazzard
 *
 * Created on 12 February 2020, 20:28
 */

#ifndef CONFIG_H
#define	CONFIG_H

// PIC16F690 Configuration Bit Settings

// 'C' source line config statements

// CONFIG
#pragma config FOSC = INTRCIO   // Oscillator Selection bits (INTOSCIO oscillator: I/O function on RA4/OSC2/CLKOUT pin, I/O function on RA5/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled and can be enabled by SWDTEN bit of the WDTCON register)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = ON       // MCLR Pin Function Select bit (MCLR pin function is MCLR)
#pragma config CP = OFF         // Code Protection bit (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)
#pragma config BOREN = OFF      // Brown-out Reset Selection bits (BOR disabled)
#pragma config IESO = ON        // Internal External Switchover bit (Internal External Switchover mode is enabled)
#pragma config FCMEN = ON       // Fail-Safe Clock Monitor Enabled bit (Fail-Safe Clock Monitor is enabled)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>
#include <stdbool.h>
#define _XTAL_FREQ 8000000      // Internal clock 2MHz

// define input and output pins
// 4 bit LCD control
#define RS PORTCbits.RC0        // pin 16
#define EN PORTCbits.RC1        // pin 15
#define D7 PORTCbits.RC2        // pin 14
#define D6 PORTCbits.RC3        // pin 7
#define D5 PORTCbits.RC4        // pin 6
#define D4 PORTCbits.RC5        // pin 5
// rotary encoder
#define DT PORTCbits.RC6        // pin 8
#define CLK PORTCbits.RC7       // pin 9
#define SW PORTAbits.RA5        // pin 2
//output relays
#define RL1 PORTAbits.RA2       // pin 7
#define RL2 PORTBbits.RB6       // pin 11
#define RL3 PORTBbits.RB4       // pin 13
// serial interface
#define TX PORTBbits.RB7        // pin 10


enum {LOW, HIGH};

typedef unsigned char uchar;
volatile uchar state = 2;        // state variable for encDebounce function
volatile uchar count = 0;
volatile bool CWflag = 0;
volatile bool ACWflag = 0;
#endif	/* CONFIG_H */

