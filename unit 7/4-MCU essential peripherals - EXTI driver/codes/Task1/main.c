/*
 * LCD_Keypad_atmega32.c
 *
 * Created: 7/7/2022 1:17:05 PM
 * Author : momen
 */ 

#include "LCD\LCD.h"

int main(void)
{
	LCD_init();

	while (1) 
    {
		LCD_send_string("Learn in depth");
		_delay_ms(2000);
		LCD_send_command(LCD_CLEAR_SCREEN);
		_delay_ms(2000);
    }
}

