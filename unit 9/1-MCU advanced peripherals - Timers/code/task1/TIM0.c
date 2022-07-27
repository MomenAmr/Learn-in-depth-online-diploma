/*
 * TIM0.c
 *
 * Created: 7/27/2022 1:14:06 PM
 *  Author: momen
 */ 

#include "Include/TIM0.h"

P_CALLBACK GL_PTR[2] = {0,0};

void MCAL_TIM0_Init(uint8_t mode, uint8_t clock, uint8_t output, uint8_t compare)
{
	TCCR0 = mode | clock | output ;
	OCR0 = compare;
	
	if(clock == CLK_T0_RISE || clock == CLK_T0_FALL) TCNT0 =0x01;
	if(output) MCAL_GPIO_Init(GPIOB,GPIO_PIN_3,MODE_OUTPUT_PP);
	
}


void MCAL_TIM0_IRQ(uint8_t interrupt, P_CALLBACK of_ptr, P_CALLBACK com_ptr)
{
	if(interrupt != IRQ_NONE)
	{
		TIMSK |= interrupt;
		GL_PTR[0] = of_ptr;
		GL_PTR[1] = com_ptr;
	}
}


void MCAL_TIM0_Stop()
{
	TCCR0 = 0;
	TCNT0 = 0;
	OCR0 = 0;
	TIMSK &= 0xfc;
}


void MCAL_TIM0_SetOCR(uint8_t compare)
{
	OCR0 = compare;
}


void MCAL_TIM0_GetCNT(uint8_t* count)
{
	*count = TCNT0;
}

ISR (TIMER0_OVF_vect)
{
	GL_PTR[0]();
}

ISR (TIMER0_COMP_vect)
{
	GL_PTR[1]();
}