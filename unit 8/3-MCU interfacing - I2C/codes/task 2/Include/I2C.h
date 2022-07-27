/*
 * I2C.h
 *
 * Created: 7/24/2022 10:27:19 AM
 *  Author: momen
 */ 


#ifndef I2C_H_
#define I2C_H_

//-----------------------------------------------------------------------------------
//includes
//-----------------------------------------------------------------------------------

#include "atmega32a_device_header.h"

//===================================================================================

//-----------------------------------------------------------------------------------
//Macros configuration references
//-----------------------------------------------------------------------------------

// @ref I2C_BITS_define
#define  TWINT							((uint8_t)0x80)
#define  TWEA							((uint8_t)0x40)
#define  TWSTA							((uint8_t)0x20)
#define  TWSTO							((uint8_t)0x10)
#define  TWWC							((uint8_t)0x08)
#define  TWEN							((uint8_t)0x04)
#define  TWIE							((uint8_t)0x01)

// @ref I2C_MODE_define
#define  MODE_MASTER					((uint8_t)0x00)
#define  MODE_SALVE						((uint8_t)0x01)

// @ref I2C_STATUS_define
#define  MASTER_START_SUCCESS			((uint8_t)0x08)
#define  MASTER_RESTART_SUCCESS			((uint8_t)0x10)
#define  MASTER_SLA_W_ACK_TRANSMITT		((uint8_t)0x18)
#define  MASTER_DATA_ACK_TRANSMITT		((uint8_t)0x28)
#define  MASTER_ARB_LOST				((uint8_t)0x38)
#define  MASTER_SLA_R_ACK_TRANSMITT		((uint8_t)0x40)
#define  MASTER_DATA_ACK_RECEIVE		((uint8_t)0x50)	

#define  SLAVE_SLA_W_ACK_RECEIVE		((uint8_t)0x60)
#define  SLAVE_DATA_ACK_RECEIVE			((uint8_t)0x80)
#define  SLAVE_STOP_RESTART_RECEIVE		((uint8_t)0xA0)
#define  SLAVE_SLA_R_ACK_RECEIVE		((uint8_t)0xA8)
#define  SLAVE_DATA_ACK_TRANSMITT		((uint8_t)0xB8)


//===================================================================================

//-----------------------------------------------------------------------------------
//APIs supported by MCAL I2C driver
//-----------------------------------------------------------------------------------
void MCAL_I2C_Init(uint8_t mode, uint32_t bitrate, uint8_t address);
uint8_t MCAL_I2C_Write(uint8_t mode, uint8_t data);
uint8_t MCAL_I2C_Read(uint8_t mode, uint8_t* data);

void MCAL_I2C_Start();
void MCAL_I2C_Stop();

//===================================================================================



#endif /* I2C_H_ */