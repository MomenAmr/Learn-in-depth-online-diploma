/*
 * MAX7219.h
 *
 * Created: 7/21/2022 4:23:32 PM
 *  Author: momen
 */ 


#ifndef MAX7219_H_
#define MAX7219_H_
//-----------------------------------------------------------------------------------
//includes
//-----------------------------------------------------------------------------------

#include "SPI.h"
#include "GPIO.h"

//===================================================================================

//-----------------------------------------------------------------------------------
//Macros configuration references
//-----------------------------------------------------------------------------------

//@ref OPERATION_define
#define  NO_OP						((uint8_t)0x00)
#define  DIGIT_0					((uint8_t)0x01)
#define  DIGIT_1					((uint8_t)0x02)
#define  DIGIT_2					((uint8_t)0x03)
#define  DIGIT_3					((uint8_t)0x04)
#define  DIGIT_4					((uint8_t)0x05)
#define  DIGIT_5					((uint8_t)0x06)
#define  DIGIT_6					((uint8_t)0x07)
#define  DIGIT_7					((uint8_t)0x08)
#define  DECODE_MODE				((uint8_t)0x09)
#define  INTINSITY					((uint8_t)0x0A)
#define  SCAN_LIMIT					((uint8_t)0x0B)
#define  SHUTDOWN					((uint8_t)0x0C)


// @ref DECODE_MODE_define
#define  DECODE_NO					((uint8_t)0x00)
#define  DECODE_DIGIT0				((uint8_t)0x01)
#define  DECODE_DIGIT0_3			((uint8_t)0xF0)
#define  DECODE_DIGIT0_7			((uint8_t)0xFF)

// @ref SHUTDOWN_define
#define  SHUTDOWN_MODE				((uint8_t)0x00)
#define  NORMAL_OPERATION			((uint8_t)0x01)

// @ref INTINSITY_define
//takes values between 0X00 & 0X0F the more the intense
#define	 INTENSITY_MAX				((uint8_t)0x0F)

// @ref SCAN_LIMIT_define
//takes values between 0X00 & 0X07 from digit0 is the limit to digit7 
#define	 DIGIT_ALL					((uint8_t)0x07)

//===================================================================================

//-----------------------------------------------------------------------------------
//APIs supported by MAX7219 SPI driver
//-----------------------------------------------------------------------------------

void MAX_SEND (uint8_t destination, uint8_t data);

//===================================================================================


#endif /* MAX7219_H_ */