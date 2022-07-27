/*
 * SPI.h
 *
 * Created: 7/21/2022 11:05:11 AM
 *  Author: momen
 */ 


#ifndef SPI_H_
#define SPI_H_

//-----------------------------------------------------------------------------------
//includes
//-----------------------------------------------------------------------------------

#include "atmega32a_device_header.h"
#include "GPIO.h"

//===================================================================================

//-----------------------------------------------------------------------------------
//Macros configuration references
//-----------------------------------------------------------------------------------

//@ref SPI_SPEED_define
#define  SPI_SPEED_DIV4				((uint8_t)0x00)
#define  SPI_SPEED_DIV16			((uint8_t)0x01)
#define  SPI_SPEED_DIV64			((uint8_t)0x02)
#define  SPI_SPEED_DIV128			((uint8_t)0x03)
#define  SPI_SPEED_DIV2				((uint8_t)0x04)
#define  SPI_SPEED_DIV8				((uint8_t)0x05)
#define  SPI_SPEED_DIV32			((uint8_t)0x06)

// @ref SPI_MODE_define
#define  MODE_SPI_SALVE				((uint8_t)0x00)
#define  MODE_SPI_MASTER			((uint8_t)0x10)

// @ref SPI_CLOCK_define
#define  MODE_CLK_RISE				((uint8_t)0x00)
#define  MODE_CLK_FALL				((uint8_t)0x08)

// @ref SPI_SAMPLE_define
#define  MODE_SAMPLE_LEAD			((uint8_t)0x00)
#define  MODE_SAMPLE_TRAIL			((uint8_t)0x04)


//===================================================================================

//-----------------------------------------------------------------------------------
//APIs supported by MCAL SPI driver
//-----------------------------------------------------------------------------------

void MCAL_SPI_Init (uint8_t mode, uint8_t speed, uint8_t polarity, uint8_t phase);
uint8_t MCAL_SPI_TRANSEIV(uint8_t data);

//===================================================================================

#endif /* SPI_H_ */