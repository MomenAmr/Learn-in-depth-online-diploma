/*
 * MAX7219.c
 *
 * Created: 7/21/2022 4:23:44 PM
 *  Author: momen
 */ 

#include "Include/MAX7219.h"


void MAX_SEND (uint8_t destination, uint8_t data)
{
	MCAL_GPIO_WRITE_PIN(GPIOB, GPIO_PIN_4, PIN_LOW);
	MCAL_SPI_TRANSEIV(destination);
	MCAL_SPI_TRANSEIV(data);
	MCAL_GPIO_WRITE_PIN(GPIOB, GPIO_PIN_4, PIN_HIGH);
}
