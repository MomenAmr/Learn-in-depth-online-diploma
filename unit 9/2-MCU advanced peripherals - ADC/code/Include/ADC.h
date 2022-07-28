/*
 * ADC.h
 *
 * Created: 7/28/2022 11:01:07 AM
 *  Author: momen
 */ 


#ifndef ADC_H_
#define ADC_H_

//-----------------------------------------------------------------------------------
//includes
//-----------------------------------------------------------------------------------

#include "atmega32a_device_header.h"

//===================================================================================

//-----------------------------------------------------------------------------------
//Macros configuration references
//-----------------------------------------------------------------------------------

//@ref ADC_VOLTAGE_REF_define
#define ADC_VOLTAGE_AREF					((uint8_t)0x00)
#define ADC_VOLTAGE_INTERNAL_AVCC			((uint8_t)0x40)
#define ADC_VOLTAGE_INTERNAL_256			((uint8_t)0xC0)

// @ref ANALOG_CHANNEL_define
#define ADC_CHANNEL0						((uint8_t)0x00)
#define ADC_CHANNEL1						((uint8_t)0x01)
#define ADC_CHANNEL2						((uint8_t)0x02)
#define ADC_CHANNEL3						((uint8_t)0x03)
#define ADC_CHANNEL4						((uint8_t)0x04)
#define ADC_CHANNEL5						((uint8_t)0x05)
#define ADC_CHANNEL6						((uint8_t)0x06)
#define ADC_CHANNEL7						((uint8_t)0x07)

//@ref ADC_PRESCALER_define
#define ADC_2								((uint8_t)0x01)
#define ADC_4								((uint8_t)0x02)
#define ADC_8								((uint8_t)0x03)
#define ADC_16								((uint8_t)0x04)
#define ADC_32								((uint8_t)0x05)
#define ADC_64								((uint8_t)0x06)
#define ADC_128								((uint8_t)0x07)

//===================================================================================

//-----------------------------------------------------------------------------------
//APIs supported by MCAL ADC driver
//-----------------------------------------------------------------------------------

void MCAL_ADC_Init(uint8_t vref, uint8_t prescaler);
uint16_t MCAL_ADC_Read(uint8_t channel);

//===================================================================================



#endif /* ADC_H_ */