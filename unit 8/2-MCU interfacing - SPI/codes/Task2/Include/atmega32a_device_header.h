/*
 * atmega32a_device_header.h
 *
 * Created: 7/17/2022 7:16:28 AM
 *  Author: momen
 */ 


#ifndef ATMEGA32A_DEVICE_HEADER_H_
#define ATMEGA32A_DEVICE_HEADER_H_

//-----------------------------------------------------------------------------------
//includes
//-----------------------------------------------------------------------------------

#include <stdint.h>

//===================================================================================

//-----------------------------------------------------------------------------------
//Base addresses for peripherals
//-----------------------------------------------------------------------------------

#define GPIOA_BASE			0x39
#define GPIOB_BASE			0x36
#define GPIOC_BASE			0x33
#define GPIOD_BASE			0x30

#define SFIOR				0x50

#define SPI_BASE			0X2D

#define UBRRL				(*(volatile uint8_t*)0x29)
#define UCSRB				(*(volatile uint8_t*)0x2A)
#define UCSRA				(*(volatile uint8_t*)0x2B)
#define UDR					(*(volatile uint8_t*)0x2C)
#define UBRRH				(*(volatile uint8_t*)0x40)
#define UCSRC				(*(volatile uint8_t*)0x40)

//===================================================================================

//-----------------------------------------------------------------------------------
//Peripherals registers
//-----------------------------------------------------------------------------------

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//GPIO register
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
typedef struct
{
	volatile uint8_t PIN;
	volatile uint8_t DDR;
	volatile uint8_t PORT;
	
}GPIO_t;

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//SPI register
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
typedef struct
{
	volatile uint8_t SPCR;
	volatile uint8_t SPSR;
	volatile uint8_t SPDR;
	
}SPI_t;

//===================================================================================

//-----------------------------------------------------------------------------------
//Peripheral instants
//-----------------------------------------------------------------------------------

#define GPIOA							((GPIO_t *)GPIOA_BASE)
#define GPIOB							((GPIO_t *)GPIOB_BASE)
#define GPIOC							((GPIO_t *)GPIOC_BASE)
#define GPIOD							((GPIO_t *)GPIOD_BASE)

#define SPI								((SPI_t *)SPI_BASE)

//===================================================================================

//-----------------------------------------------------------------------------------
//Enable & disable macros
//-----------------------------------------------------------------------------------

#define PUR_EN								(*(uint8_t*)SFIOR = 0X00)
#define PUR_DIS								(*(uint8_t*)SFIOR = 0X04)

#define SPI_EN								(SPI->SPCR |= 0X40)

//===================================================================================

#endif /* ATMEGA32A_DEVICE_HEADER_H_ */