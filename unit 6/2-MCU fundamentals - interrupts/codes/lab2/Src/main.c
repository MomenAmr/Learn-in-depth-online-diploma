/*
 * main.c
 *
 *  Created on: Jul 3, 2022
 *      Author: momen amr
 */

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#include<stdint.h>
typedef volatile unsigned int vuint32_t;


#define RCC_BASE             0x40021000
#define RCC_APB2ENR_PTR    	*((vuint32_t *)(RCC_BASE + 0x18))

#define GPIOA_BASE            0x40010800
#define GPIOA_CRL_PTR 		*((vuint32_t *)(GPIOA_BASE + 0x00))
#define GPIOA_CRH_PTR      	*((vuint32_t *)(GPIOA_BASE + 0x04))
#define GPIOA_ODR_PTR      	*((vuint32_t *)(GPIOA_BASE + 0x0c))

#define AFIO_BASE 			0x40010000
#define AFIO_EXTICR1_PRT 	*((vuint32_t *)(AFIO_BASE + 0x08))

#define EXTI_BASE 			0x40010400
#define EXTI_IMR_PTR		*((vuint32_t *)(EXTI_BASE+0x00))
#define EXTI_RTSR_PTR 		*((vuint32_t *)(EXTI_BASE+0x08))
#define EXTI_PR_PTR 		*((vuint32_t *)(EXTI_BASE+0x14))

#define NVIC_ISER0			*((vuint32_t *)(0xE000E100))

void CLK_init()
{
	//to enable clock to AFIO & GPIO
	RCC_APB2ENR_PTR |= 0b101;
}

void GPIO_init()
{
	//to set modes for pin0 and pin13 by default pin0 is configured as required but we do it anyway
	GPIOA_CRL_PTR &= 0xfffffff0;
	GPIOA_CRL_PTR |= 0x00000004;
	GPIOA_CRH_PTR &= 0xff0fffff;
	GPIOA_CRH_PTR |= 0x00200000;
}

void EXTI_init()
{
	//to set PA0 is the interrupt pin by default is configured as required but we do it anyway
	AFIO_EXTICR1_PRT = 0;
	//to enable the mask for EXTI0
	EXTI_IMR_PTR |= 1;
	//to enable the rising edge trigger for EXT0
	EXTI_RTSR_PTR |= 1;
	//to enable the NVIC mask for EXTI0
	NVIC_ISER0 |=(1<<6);
}

void main()
{
	CLK_init();
	GPIO_init();
	EXTI_init();

	while(1);
}

void EXTI0_IRQHandler(void)
{
	//to clear the pending status register
	EXTI_PR_PTR |= 1;
	//to toggle pin13
	GPIOA_ODR_PTR ^= (1<<13);
}
