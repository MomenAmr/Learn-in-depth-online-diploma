/*
 * LCD_Keypad_atmega32.c
 *
 * Created: 7/7/2022 1:17:05 PM
 * Author : momen
 */ 

#define	F_CPU 8000000UL
#include <util/delay.h>
#include "Include/GPIO.h"
#include "Include/SPI.h"

int main(void)
{
	MCAL_SPI_Init(MODE_SPI_MASTER, SPI_SPEED_DIV4, MODE_CLK_RISE, MODE_SAMPLE_LEAD);
	
	MCAL_GPIO_Init(GPIOA,GPIO_PIN_0, MODE_OUTPUT_PP);
	MCAL_GPIO_Init(GPIOA,GPIO_PIN_1, MODE_OUTPUT_PP);
	MCAL_GPIO_Init(GPIOA,GPIO_PIN_2, MODE_OUTPUT_PP);
	MCAL_GPIO_Init(GPIOA,GPIO_PIN_3, MODE_OUTPUT_PP);
	MCAL_GPIO_Init(GPIOA,GPIO_PIN_4, MODE_OUTPUT_PP);
	MCAL_GPIO_Init(GPIOA,GPIO_PIN_5, MODE_OUTPUT_PP);
	MCAL_GPIO_Init(GPIOA,GPIO_PIN_6, MODE_OUTPUT_PP);
	MCAL_GPIO_Init(GPIOA,GPIO_PIN_7, MODE_OUTPUT_PP);

	while (1) 
    {
		for(uint8_t i =0; i<255;i++)
		{
			MCAL_GPIO_WRITE_PORT(GPIOA, MCAL_SPI_TRANSEIV(i));
			_delay_ms(100);
		}			
			
	}
}
