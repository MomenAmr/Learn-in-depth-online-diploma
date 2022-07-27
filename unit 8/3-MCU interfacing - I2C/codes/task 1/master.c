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
	MCAL_I2C_Init(MODE_MASTER, 100000, 0);
	
	uint8_t C=0;
	
	while (1) 
    {		
		MCAL_I2C_Start();
		while (MCAL_I2C_Write(MODE_MASTER, 0XF0+0) != MASTER_SLA_W_ACK_TRANSMITT);
		while (MCAL_I2C_Write(MODE_MASTER, C++) != MASTER_DATA_ACK_TRANSMITT);
		MCAL_I2C_Stop();
		_delay_ms(100);		
	}
}
