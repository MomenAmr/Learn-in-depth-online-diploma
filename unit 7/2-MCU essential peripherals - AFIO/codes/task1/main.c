/*
 * LCD_Keypad_atmega32.c
 *
 * Created: 7/7/2022 1:17:05 PM
 * Author : momen
 */ 

#include "LCD\LCD.h"
#include "KEYPAD\KEYPAD.h"

int main(void)
{
	LCD_init();
	KEYPAD_init();
	char c;
	int i=0;
	while (1) 
    {
		c = KEYPAD_getc();
		switch(c)
		{
			case ('!'):
			LCD_send_command(LCD_CLEAR_SCREEN);
			break;
			
			case ('N'):
			break;
			
			default:
			i++;
			LCD_send_data(c);
			if (i == 16)
			{
				LCD_send_command(LCD_BEGIN_AT_SECOND_ROW);
			}
			else if (i == 32)
			{
				LCD_send_command(LCD_CLEAR_SCREEN);
				i = 0;
			}
		}
		_delay_ms(50);
    }
}

