/*
 * LCD.c
 *
 * Created: 7/7/2022 1:18:21 PM
 *  Author: momen
 */ 

#include "Include/LCD.h"

void wait_loop(int x)
{
	volatile int i,j;
	for(i=0;i<x;i++)
	{
		for (j=0;j<255;j++);
	}
}

void LCD_init()
{
	//MCAL_GPIO_Init(LCD_DATA, D0,MODE_OUTPUT_PP);
	//MCAL_GPIO_Init(LCD_DATA, D1,MODE_OUTPUT_PP);
	//MCAL_GPIO_Init(LCD_DATA, D2,MODE_OUTPUT_PP);
	//MCAL_GPIO_Init(LCD_DATA, D3,MODE_OUTPUT_PP);
	MCAL_GPIO_Init(LCD_DATA, D4,MODE_OUTPUT_PP);
	MCAL_GPIO_Init(LCD_DATA, D5,MODE_OUTPUT_PP);
	MCAL_GPIO_Init(LCD_DATA, D6,MODE_OUTPUT_PP);
	MCAL_GPIO_Init(LCD_DATA, D7,MODE_OUTPUT_PP);
	
	MCAL_GPIO_Init(LCD_CTRL, RS,MODE_OUTPUT_PP);
	MCAL_GPIO_Init(LCD_CTRL, RW,MODE_OUTPUT_PP);
	MCAL_GPIO_Init(LCD_CTRL, EN,MODE_OUTPUT_PP);
	
	wait_loop(200);
	
	#ifdef _4_BIT
	LCD_send_command(LCD_RETURN_HOME);
	LCD_send_command(LCD_FUNCTION_4BIT_2LINES);
	#endif
	
	#ifdef _8_BIT
	LCD_send_command(LCD_FUNCTION_8BIT_2LINES);
	#endif
	
	LCD_send_command(LCD_ENTRY_MODE);
	LCD_send_command(LCD_BEGIN_AT_FIRST_ROW);
	LCD_send_command(LCD_DISP_ON);
}

void LCD_send_command(unsigned char command)
{
	#ifdef _4_BIT
	LCD_busy();
	MCAL_GPIO_WRITE_PORT_SEL(LCD_DATA, UPPER_NIBBLE, command);
	LCD_pulse();
	MCAL_GPIO_WRITE_PORT_SEL(LCD_DATA, UPPER_NIBBLE, (command <<4));
	LCD_pulse();
	#endif
	
	#ifdef _8_BIT
	LCD_busy();
	MCAL_GPIO_WRITE_PIN(LCD_CTRL, RS, PIN_LOW);
	MCAL_GPIO_WRITE_PORT(LCD_DATA,command);
	LCD_pulse();
	#endif
}

void LCD_busy()
{
	#ifdef _4_BIT
	MCAL_GPIO_Init(LCD_CTRL, D7,MODE_INPUT_FLO);
	MCAL_GPIO_WRITE_PIN(LCD_CTRL, RS, PIN_LOW);
	MCAL_GPIO_WRITE_PIN(LCD_CTRL, RW, PIN_HIGH);
	
	LCD_pulse();
	wait_loop(1);
	LCD_pulse();
	
	MCAL_GPIO_Init(LCD_DATA, D7,MODE_OUTPUT_PP);
	MCAL_GPIO_WRITE_PIN(LCD_CTRL, RW, PIN_LOW);
	#endif
	
	#ifdef _8_BIT
	MCAL_GPIO_Init(LCD_CTRL, D7,MODE_INPUT_FLO);
	MCAL_GPIO_WRITE_PIN(LCD_CTRL, RS, PIN_LOW);
	MCAL_GPIO_WRITE_PIN(LCD_CTRL, RW, PIN_HIGH);
	
	LCD_pulse();
	
	MCAL_GPIO_Init(LCD_DATA, D7,MODE_OUTPUT_PP);
	MCAL_GPIO_WRITE_PIN(LCD_CTRL, RW, PIN_LOW);
	#endif
}

void LCD_pulse()
{
	MCAL_GPIO_WRITE_PIN(LCD_CTRL, EN, PIN_HIGH);
	wait_loop(1);
	MCAL_GPIO_WRITE_PIN(LCD_CTRL, EN, PIN_LOW);
}

void LCD_send_data(unsigned char data)
{
	#ifdef _4_BIT
	LCD_busy();
	MCAL_GPIO_WRITE_PIN(LCD_CTRL, RS, PIN_HIGH);
	MCAL_GPIO_WRITE_PORT_SEL(LCD_DATA, UPPER_NIBBLE, data);
	LCD_pulse();
	MCAL_GPIO_WRITE_PORT_SEL(LCD_DATA, UPPER_NIBBLE, (data <<4));
	LCD_pulse();
	#endif
	
	#ifdef _8_BIT
	LCD_busy();
	MCAL_GPIO_WRITE_PIN(LCD_CTRL, RS, PIN_HIGH);
	MCAL_GPIO_WRITE_PORT(LCD_DATA,data);
	LCD_pulse();
	#endif
}

void LCD_send_string(char* string)
{
	volatile int count = 0;
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
