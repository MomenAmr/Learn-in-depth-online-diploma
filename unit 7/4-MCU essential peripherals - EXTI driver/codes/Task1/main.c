/*
 * LCD_Keypad_atmega32.c
 *
 * Created: 7/7/2022 1:17:05 PM
 * Author : momen
 */ 

#include "Include/GPIO.h"
#include "include/LCD.h"


int main(void)
{
	LCD_init();

	while (1) 
    {
		LCD_send_string("Learn-in-depth");
		wait_loop(200);
		LCD_send_command(LCD_CLEAR_SCREEN);
		wait_loop(200);
	}
}

