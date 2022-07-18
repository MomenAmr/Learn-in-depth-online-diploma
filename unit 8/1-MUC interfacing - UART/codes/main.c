/*
 * LCD_Keypad_atmega32.c
 *
 * Created: 7/7/2022 1:17:05 PM
 * Author : momen
 */ 

#include "include/LCD.h"
#include "Include/USART.h"

volatile char str[100];
int main(void)
{
	LCD_init();
	LCD_send_string("LCD initialized");
	LCD_send_command(LCD_BEGIN_AT_SECOND_ROW);
	LCD_send_string("perfectly");
	
	MCAL_USART_Init();
	MCAL_USART_SEND_STR("UART initialized and working perfectly!");
	
	wait_loop(1000);
	LCD_send_command(LCD_CLEAR_SCREEN);

	while (1) 
    {
		char*p = MCAL_USART_RECV_STR(str);
		LCD_send_command(LCD_CLEAR_SCREEN);
		LCD_send_string(p);
	}
}

