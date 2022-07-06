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

/* To toggle a pin onto stm32f103cx we need first to enable rcc module clock sent to gpio module, that is done by setting
 * IOPAEN bit (bit2) in APB2ENR register which has offset of 0x18 to rcc module base address of 0x40021000.*/
#define RCC_BASE             0x40021000
#define RCC_APB2ENR         (RCC_BASE + 0x18)
#define RCC_CFGR			(RCC_BASE + 0x04)
#define RCC_CR				(RCC_BASE)

/* Secondly we must set pin13 mode bits (bit20->bit23) in CRH register to (2) which has offset of 0x04 to GPIO_PA module base
 * address of 0x40010800 and toggle pin13 (bit13) in GPIOA_ODR register which has offset of 0x0c to GPIO_PA module address.*/
#define GPIO_BASE            0x40010800
#define GPIO_CRH            (GPIO_BASE + 0x04)
#define GPIO_ODR            (GPIO_BASE + 0x0c)

/* To make everything easy we can define some macros for pointers to access the registers needed for operation*/
#define RCC_APB2ENR_PTR    	*((vuint32_t *)RCC_APB2ENR)
#define RCC_CFGR_PTR		*((vuint32_t *)RCC_CFGR)
#define RCC_CR_PTR			*((vuint32_t *)RCC_CR)
#define GPIO_CRH_PTR      	*((vuint32_t *)GPIO_CRH)

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

void main()
{
	RCC_CFGR_PTR |= 0b10;				/* to set SYSCLK source to PLL*/
	RCC_CFGR_PTR |= (0b0110<<18);		/* to set PLL multiplier to 8 */
	RCC_CFGR_PTR |= (0b100<<8);			/* to set ABP1 prescaler to 2 */
	RCC_CFGR_PTR |= (0b101<<11);		/* to set ABP2 prescaler to 4 */
	RCC_CR_PTR |= (1<<24);				/* to enable PLL clock source */
	RCC_APB2ENR_PTR |= (1<<2);			/* to set bit2 in RCC_APB2ENR */
	GPIO_CRH_PTR &= 0xff0fffff;			/* to clear bit20->bit23 first*/
	GPIO_CRH_PTR |= 0x00200000;			/* to set bit20->bit23 to 2   */

	int i;
	while (1)
	{
		R_ODR->pinwise.pin13 = 1;		/* to set pin13               */
		for(i=0;i<50000;i++);			/* a loop just to induce delay*/
		R_ODR->pinwise.pin13 = 0;		/* to clear pin13             */
		for(i=0;i<50000;i++);			/* a loop just to induce delay*/
	}
}

