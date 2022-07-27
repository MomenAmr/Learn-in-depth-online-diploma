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

int main(void)
{
	MCAL_TIM0_Init(TIM0_CTC,CLK_T0_RISE,OC0_TOG,5);
	
	while (1) 
    {		

	}
}
