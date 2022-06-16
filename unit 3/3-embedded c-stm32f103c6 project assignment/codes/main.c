/*
 * main.c
 *
 *  Created on: Jun 15, 2022
 *      Author: momen amr
 */

#include<stdint.h>
typedef volatile unsigned int vuint32_t;

/* To toggle a pin onto stm32f103cx we need first to enable rcc module clock sent to gpio module, that is done by setting
 * IOPAEN bit (bit2) in APB2ENR register which has offset of 0x18 to rcc module base address of 0x40021000.*/
#define RCC_BASE             0x40021000
#define RCC_APB2ENR         (RCC_BASE + 0x18)

/* Secondly we must set pin13 mode bits (bit20->bit23) in CRH register to (2) which has offset of 0x04 to GPIO_PA module base
 * address of 0x40010800 and toggle pin13 (bit13) in GPIOA_ODR register which has offset of 0x0c to GPIO_PA module address.*/
#define GPIO_BASE            0x40010800
#define GPIO_CRH            (GPIO_BASE + 0x04)
#define GPIO_ODR            (GPIO_BASE + 0x0c)

/* To make everything easy we can define some macros for pointers to access the registers needed for operation*/
#define RCC_APB2ENR_PTR    *((vuint32_t *)RCC_APB2ENR)
#define GPIO_CRH_PTR       *((vuint32_t *)GPIO_CRH)

/* We can define a union/structure object to deal with GPIO_CRH register easily also a pointer to it*/
typedef union
{
	vuint32_t all_pins;
	struct
	{
		vuint32_t preserved:13;
		vuint32_t pin13:1;
	}pinwise;
}R_GPIO_ODR_t;

volatile R_GPIO_ODR_t * R_ODR = (volatile R_GPIO_ODR_t*)GPIO_ODR;
unsigned char const c_variables[5] = {1,2,3,4,5};
unsigned int g_variables[3];

void main()
{
	int i;
	RCC_APB2ENR_PTR |= (1<<2);           /* to set bit2 in RCC_APB2ENR */
	GPIO_CRH_PTR &= 0xff0fffff;          /* to clear bit20->bit23 first*/
	GPIO_CRH_PTR |= 0x00200000;          /* to set bit20->bit23 to 2   */
	
	/* just to see if initializing bss section worked as it should */
	g_variables[0] = 0x11111111;
	g_variables[1] = 0x22222222;
	g_variables[2] = 0x33333333;

	while (1)
	{
		R_ODR->pinwise.pin13 = 1;    /* to set pin13               */
		for(i=0;i<50000;i++);        /* a loop just to induce delay*/
		R_ODR->pinwise.pin13 = 0;    /* to clear pin13             */
		for(i=0;i<50000;i++);        /* a loop just to induce delay*/
	}
}
