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
#include "Include/MAX7219.h"

int main(void)
{
	MCAL_SPI_Init(MODE_SPI_MASTER, SPI_SPEED_DIV4, MODE_CLK_RISE, MODE_SAMPLE_LEAD);
	
	MAX_SEND(DECODE_MODE, DECODE_DIGIT0_7);
	MAX_SEND(INTINSITY, INTENSITY_MAX);
	MAX_SEND(SCAN_LIMIT, DIGIT_ALL);
	MAX_SEND(SHUTDOWN, NORMAL_OPERATION);

	uint8_t x = 0;
	while (1) 
    {
		for(uint8_t i = 1; i<9;i++)
		{
			MAX_SEND(i,x++);
			_delay_ms(1000);
		}
	}
}

