/*
 * TIM0.h
 *
 * Created: 7/27/2022 1:13:52 PM
 *  Author: momen
 */ 


#ifndef TIM0_H_
#define TIM0_H_

//-----------------------------------------------------------------------------------
//includes
//-----------------------------------------------------------------------------------

#include "atmega32a_device_header.h"
#include "GPIO.h"
#include <avr/interrupt.h>

//===================================================================================

typedef void(*P_CALLBACK)();

//-----------------------------------------------------------------------------------
//Macros configuration references
//-----------------------------------------------------------------------------------

// @ref WAVEFORM_GEN_define
#define TIM0_NORMAL						0x00
#define TIM0_CTC						0x08
#define TIM0_PHASEPWM					0x40
#define TIM0_FASTPWM					0x48

// @ref COMPARE_MATCH_define
#define OC0_NONE						0x00
#define OC0_TOG							0x10
#define OC0_CLR							0x20
#define OC0_SET							0x30

// @ref CLOCK_SELECT_define
#define CLK_NONE						0x00
#define CLK_1							0x01
#define CLK_8							0x02
#define CLK_64							0x03
#define CLK_256							0x04
#define CLK_1024						0x05
#define CLK_T0_FALL						0x06
#define CLK_T0_RISE						0x07

// @ref PWM_FAST_FREQ_define
#define FREQ_256						0x01
#define FREQ_2048						0x02
#define FREQ_16384						0x03
#define FREQ_65563						0x04
#define FREQ_262144						0x05

// @ref PWM_PHASE_FREQ_define
#define FREQ_510						0x01
#define FREQ_4080						0x02
#define FREQ_32640						0x03
#define FREQ_130560						0x04
#define FREQ_522240						0x05

// @ref IRQ_define
#define IRQ_NONE						0x00
#define IRQ_OF							0x01
#define IRQ_COM							0x02
#define IRQ_OF_COM						0x03

//===================================================================================

//-----------------------------------------------------------------------------------
//APIs supported by MCAL TIM0 driver
//-----------------------------------------------------------------------------------
void MCAL_TIM0_Init(uint8_t mode, uint8_t clock, uint8_t output, uint8_t compare);
void MCAL_TIM0_IRQ(uint8_t interrupt, P_CALLBACK com_ptr, P_CALLBACK of_ptr);
void MCAL_TIM0_Stop();

void MCAL_TIM0_SetOCR(uint8_t compare);
void MCAL_TIM0_GetCNT(uint8_t* count);

//===================================================================================



#endif /* TIM0_H_ */