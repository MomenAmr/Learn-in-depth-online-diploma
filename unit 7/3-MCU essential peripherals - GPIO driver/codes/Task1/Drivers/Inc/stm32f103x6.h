/*
 * stm32f103x6.h
 *
 *  Created on: Jul 13, 2022
 *      Author: momen
 */

#ifndef INC_STM32F103X6_H_
#define INC_STM32F103X6_H_

//-----------------------------------------------------------------------------------
//includes
//-----------------------------------------------------------------------------------

#include "stdlib.h"
#include "stdint.h"

//===================================================================================

//-----------------------------------------------------------------------------------
//Base addresses for memories
//-----------------------------------------------------------------------------------

#define FLASH_MEM_BASE						0X08000000UL
#define SYSTEM_MEM_BASE						0X1FFFF000UL
#define SRAM_MEM_BASE						0X20000000UL

//===================================================================================

//-----------------------------------------------------------------------------------
//Base addresses for AHB peripherals
//-----------------------------------------------------------------------------------

#define RCC_BASE							0x40021000UL

//===================================================================================

//-----------------------------------------------------------------------------------
//Base addresses for APB2 peripherals
//-----------------------------------------------------------------------------------

#define AFIO_BASE							0x40010000UL
#define EXTI_BASE							0x40010400UL
//in package LQFP48 only port A&B are used fully while port C&D are used partially while port E is not mapped
#define GPIOA_BASE							0x40010800UL
#define GPIOB_BASE							0x40010C00UL
#define GPIOC_BASE							0x40011000UL
#define GPIOD_BASE							0x40011400UL
#define GPIOE_BASE							0x40011800UL

//===================================================================================

//-----------------------------------------------------------------------------------
//Peripherals registers
//-----------------------------------------------------------------------------------

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//RCC register
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*

typedef struct
{
	volatile uint32_t CR;
	volatile uint32_t CFGR;
	volatile uint32_t CIR;
	volatile uint32_t APB2RSTR;
	volatile uint32_t APB1RSTR;
	volatile uint32_t AHBENR;
	volatile uint32_t APB2ENR;
	volatile uint32_t APB1ENR;
	volatile uint32_t BDCR;
	volatile uint32_t CSR;

}RCC_t;

//-----------------------------------------------------------------------------------

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//GPIO register
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*

typedef struct
{
	volatile uint32_t CRL;
	volatile uint32_t CRH;
	volatile uint32_t IDR;
	volatile uint32_t ODR;
	volatile uint32_t BSRR;
	volatile uint32_t BRR;
	volatile uint32_t LCKR;

}GPIO_t;

//-----------------------------------------------------------------------------------

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//AFIO register
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*

typedef struct
{
	volatile uint32_t EVCR;
	volatile uint32_t MPR;
	volatile uint32_t EXTICR1;
	volatile uint32_t EXTICR2;
	volatile uint32_t EXTICR3;
	volatile uint32_t EXTICR4;
	volatile uint32_t RESERVED;
	volatile uint32_t MPR2;

}AFIO_t;

//-----------------------------------------------------------------------------------

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//EXTI register
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*

typedef struct
{
	volatile uint32_t IMR;
	volatile uint32_t EMR;
	volatile uint32_t RTSR;
	volatile uint32_t FTSR;
	volatile uint32_t SWIER;
	volatile uint32_t PR;

}EXTI_t;

//-----------------------------------------------------------------------------------

//===================================================================================

//-----------------------------------------------------------------------------------
//Peripheral instants
//-----------------------------------------------------------------------------------

#define RCC								((RCC_t *)RCC_BASE)
#define EXTI							((EXTI_t *)EXTI_BASE)
#define AFIO							((AFIO_t *)AFIO_BASE)
#define GPIOA							((GPIO_t *)GPIOA_BASE)
#define GPIOB							((GPIO_t *)GPIOB_BASE)
#define GPIOC							((GPIO_t *)GPIOC_BASE)
#define GPIOD							((GPIO_t *)GPIOD_BASE)
#define GPIOE							((GPIO_t *)GPIOE_BASE)

//===================================================================================

//-----------------------------------------------------------------------------------
//Clock enable macros
//-----------------------------------------------------------------------------------

#define RCC_CLOCK_AFIO_EN()				(RCC->APB2ENR |= (1<<0))
#define RCC_CLOCK_GPIOA_EN()			(RCC->APB2ENR |= (1<<2))
#define RCC_CLOCK_GPIOB_EN()			(RCC->APB2ENR |= (1<<3))
#define RCC_CLOCK_GPIOC_EN()			(RCC->APB2ENR |= (1<<4))
#define RCC_CLOCK_GPIOD_EN()			(RCC->APB2ENR |= (1<<5))
#define RCC_CLOCK_GPIOE_EN()			(RCC->APB2ENR |= (1<<6))


//===================================================================================


#endif /* INC_STM32F103X6_H_ */
