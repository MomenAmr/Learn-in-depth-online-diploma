/*
 * lab1.c
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
#define GPIOA_IDR_PTR      	*((vuint32_t *)(GPIOA_BASE + 0x08))

#define GPIOB_BASE            0x40010c00
#define GPIOB_CRL_PTR 		*((vuint32_t *)(GPIOB_BASE + 0x00))
#define GPIOB_CRH_PTR      	*((vuint32_t *)(GPIOB_BASE + 0x04))
#define GPIOB_ODR_PTR      	*((vuint32_t *)(GPIOB_BASE + 0x0c))


void CLK_init()
{
	//to enable clock to GPIOA & GPIOB
	RCC_APB2ENR_PTR |= 0b1100;
}

void GPIO_init()
{
	//to set modes for pin0 and pin13 of portA as floating input
	GPIOA_CRL_PTR &= 0xffffff0f;
	GPIOA_CRL_PTR |= 0x00000040;
	GPIOA_CRH_PTR &= 0xff0fffff;
	GPIOA_CRH_PTR |= 0x00400000;

	//to set modes for pin0 and pin13 of portB as push-pull output
	GPIOB_CRL_PTR &= 0xffffff0f;
	GPIOB_CRL_PTR |= 0x00000010;
	GPIOB_CRH_PTR &= 0xff0fffff;
	GPIOB_CRH_PTR |= 0x00100000;
}

void delay_loop(int x)
{
	int i;
	for(i=0;i<x;i++);
}

void main()
{
	CLK_init();
	GPIO_init();

	//flag required for button1 non-blocking operation
	int F_A0=0;
	while(1)
	{
		//to make button1 work in single press way without blocking the other button
		if(GPIOA_IDR_PTR & 1<<1)
		{
			//if button1 is depressed then zero the flag
			F_A0 = 0;
		}
		else
		{
			//if button1 is pressed then check the flag if set then it's not the first time
			if(F_A0==0)
			{
				//if button1 is pressed for the first time then set the flag for next time and toggle
				F_A0 = 1;
				GPIOB_ODR_PTR ^= 1<<1;
			}

		}

		//to make button2 work in multi-press way
		if(GPIOA_IDR_PTR & 1<<13)
		{
			GPIOB_ODR_PTR ^= 1<<13;
		}

		delay_loop(5000);
	}
}

