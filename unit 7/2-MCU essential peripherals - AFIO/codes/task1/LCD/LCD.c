/*
 * LCD.c
 *
 * Created: 7/7/2022 1:18:21 PM
 *  Author: momen
 */ 

#include "LCD.h"

void LCD_init()
{
	DDR_LCD_CTRL = 0X0F;
	LCD_CTRL = 0X08;
	DDR_LCD_DATA = 0XF0;
	LCD_DATA = 0X30;
	_delay_ms(20);
	
	#ifdef _4_BIT
	LCD_send_command(LCD_RETURN_HOME);
	LCD_send_command(LCD_FUNCTION_4BIT_2LINES);
	#endif
	
	#ifdef _8_BIT
	LCD_send_command(LCD_FUNCTION_8BIT_2LINES);
	#endif
	
	LCD_send_command(LCD_ENTRY_MODE);
	LCD_send_command(LCD_BEGIN_AT_FIRST_ROW);
	LCD_send_command(LCD_DISP_ON_CURSOR_BLINK);
}

void LCD_send_command(unsigned char command)
{
	#ifdef _4_BIT
	LCD_busy();
	LCD_DATA = command;
	LCD_pulse();
	LCD_DATA = command <<4;
	LCD_pulse();
	#endif
	
	#ifdef _8_BIT
	LCD_busy();
	LCD_DATA = command;
	LCD_pulse();
	#endif
}

void LCD_busy()
{
	#ifdef _4_BIT
	DDR_LCD_DATA &= ~(1<<7);
	LCD_CTRL &= ~(1<<RS);
	LCD_CTRL |= 1<<RW;
	LCD_pulse();
	_delay_ms(5);
	LCD_pulse();
	DDR_LCD_DATA |= 1<<7;
	LCD_CTRL &= ~(1<<RW);
	#endif
	
	#ifdef _8_BIT
	DDR_LCD_DATA &= ~(1<<7);
	LCD_CTRL &= ~(1<<RS);
	LCD_CTRL |= 1<<RW;
	LCD_pulse();
	DDR_LCD_DATA |= 1<<7;
	LCD_CTRL &= ~(1<<RW);
	#endif
}

void LCD_pulse()
{
	LCD_CTRL |= 1<<EN;
	_delay_ms(5);
	LCD_CTRL &= ~(1<<EN);
}

void LCD_send_data(unsigned char data)
{
	#ifdef _4_BIT
	LCD_busy();
	LCD_CTRL |= 1<<RS;
	LCD_DATA = (LCD_DATA & 0x0F) | (data & 0xF0);
	LCD_pulse();
	LCD_DATA = (LCD_DATA & 0x0F) | (data <<4);
	LCD_pulse();
	#endif
	
	#ifdef _8_BIT
	LCD_busy();
	LCD_CTRL |= 1<<RS;
	LCD_DATA = data;
	LCD_pulse();
	#endif
}

void LCD_send_string(char* string)
{
	int count = 0;
	while(*string != 0)
	{
		count++;
		LCD_send_data(*string++);
		if (count == 16)
		{
			LCD_send_command(LCD_BEGIN_AT_SECOND_ROW);
		}
		else if (count == 32)
		{
			LCD_send_command(LCD_CLEAR_SCREEN);
			count = 0;
		}
	}
}
