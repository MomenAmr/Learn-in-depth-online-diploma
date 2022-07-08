/*
 * KEYPAD.h
 *
 * Created: 7/8/2022 3:12:07 PM
 *  Author: momen
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>

#define Keypad_PORT PORTD
#define DDR_Keypad_PORT DDRD
#define Keypad_DATA PIND

#define R0 0
#define R1 1
#define R2 2
#define R3 3
#define C0 4
#define C1 5
#define C2 6
#define C3 7


void KEYPAD_init(void);
char KEYPAD_getc();



#endif /* KEYPAD_H_ */