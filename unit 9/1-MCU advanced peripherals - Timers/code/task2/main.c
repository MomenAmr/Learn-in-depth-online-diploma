/*
 * LCD_Keypad_atmega32.c
 *
 * Created: 7/7/2022 1:17:05 PM
 * Author : momen
 */ 
#define	F_CPU 8000000UL
#include <util/delay.h>
#include "Include/GPIO.h"
#include "Include/TIM0.h"

volatile uint8_t threshold = 0;
volatile uint8_t flag = 0;


void overflow_callback()
{
	OCR0 = threshold;
}

int main(void)
{
	MCAL_TIM0_Init(TIM0_PHASEPWM,CLK_8,OC0_CLR,0);
	
	MCAL_TIM0_IRQ(IRQ_OF, overflow_callback, 0);
	
	sei();
	
	while (1) 
    {		
		if(flag==0)
		{
			threshold++;
			if(threshold==255) 
			{
				flag = 1;
			}
		}
		
		if(flag==1)
		{
			threshold--;
			if(threshold==0) 
			{
				flag = 0;
			}
		}

		_delay_ms(5);
	}
}
