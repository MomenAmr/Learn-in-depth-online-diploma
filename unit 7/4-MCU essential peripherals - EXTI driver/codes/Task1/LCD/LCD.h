/*
 * LCD.h
 *
 * Created: 7/7/2022 1:18:32 PM
 *  Author: momen
 */ 


#ifndef LCD_H_
#define LCD_H_

#define F_CPU 8000000UL
#include<avr/io.h>
#include<util/delay.h>

#define LCD_DATA PORTA
#define DDR_LCD_DATA DDRA
#define LCD_CTRL PORTB
#define DDR_LCD_CTRL DDRB

#define RS 1
#define RW 2
#define EN 3

//#define _8_BIT
#define _4_BIT

#define LCD_FUNCTION_8BIT_2LINES   					(0x38)
#define LCD_FUNCTION_4BIT_2LINES   					(0x28)
#define LCD_MOVE_DISP_RIGHT       					(0x1C)
#define LCD_MOVE_DISP_LEFT   						(0x18)
#define LCD_MOVE_CURSOR_RIGHT   					(0x14)
#define LCD_MOVE_CURSOR_LEFT 	  					(0x10)
#define LCD_DISP_OFF   								(0x08)
#define LCD_DISP_ON_CURSOR   						(0x0E)
#define LCD_DISP_ON_CURSOR_BLINK   					(0x0F)
#define LCD_DISP_ON_BLINK   						(0x0D)
#define LCD_DISP_ON   								(0x0C)
#define LCD_ENTRY_DEC   							(0x04)
#define LCD_ENTRY_DEC_SHIFT   						(0x05)
#define LCD_ENTRY_INC_   							(0x06)
#define LCD_ENTRY_INC_SHIFT   						(0x07)
#define LCD_BEGIN_AT_FIRST_ROW						(0x80)
#define LCD_BEGIN_AT_SECOND_ROW						(0xC0)
#define LCD_CLEAR_SCREEN							(0x01)
#define LCD_RETURN_HOME								(0x02)
#define LCD_ENTRY_MODE								(0x06)

void LCD_init();
void LCD_busy();
void LCD_pulse();
void LCD_send_command(unsigned char command);
void LCD_send_data(unsigned char data);
void LCD_send_string(char* string);

#endif /* LCD_H_ */