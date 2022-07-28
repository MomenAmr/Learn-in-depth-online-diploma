/*
 * LCD_Keypad_atmega32.c
 *
 * Created: 7/7/2022 1:17:05 PM
 * Author : momen
 */ 
#define	F_CPU 8000000UL
#include <util/delay.h>
#include "Include/LCD.h"
#include "Include/ADC.h"

int main(void)
{
	LCD_init();
	LCD_send_string("LCD");
	LCD_send_command(LCD_BEGIN_AT_SECOND_ROW);
	LCD_send_string("initialized");
	_delay_ms(1000);
	LCD_send_command(LCD_CLEAR_SCREEN);
		
	MCAL_ADC_Init(ADC_VOLTAGE_INTERNAL_AVCC, ADC_8);
	
	volatile unsigned int sen =0, sen_prev;
	volatile uint16_t temp=0;
	volatile uint8_t count=0, flag =0;
	char number[5];
	
	while (1) 
    {
		temp = MCAL_ADC_Read(ADC_CHANNEL0);
		sen = temp * 100UL / 1023;
		count = temp * 16UL / 1023;
		
		if(sen != sen_prev) 
		{
			flag = 1;
			sen_prev = sen;
		}
		else flag =0;
	
		sprintf(number, "%u", sen);
		
		if(flag)
		{
			LCD_send_command(LCD_CLEAR_SCREEN);
			LCD_send_string(number);
			LCD_send_data('%');
			LCD_send_command(LCD_BEGIN_AT_SECOND_ROW);
			for(int i=0;i<count;i++)
			{
				LCD_send_data(0xff);
			}
		}
	}
}
