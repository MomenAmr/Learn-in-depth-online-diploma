/*
 * LCD_Keypad_atmega32.c
 *
 * Created: 7/7/2022 1:17:05 PM
 * Author : momen
 */ 

#define	F_CPU 8000000UL
#include <util/delay.h>
#include "Include/GPIO.h"
#include "Include/I2C.h"

int main(void)
{
	MCAL_I2C_Init(MODE_SALVE, 0, 0xF0);
	
	uint8_t C=0;
	while (1) 
    {
		MCAL_I2C_Write(MODE_SALVE, C++);
	}
}

