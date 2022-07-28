/*
 * ADC.c
 *
 * Created: 7/28/2022 11:01:21 AM
 *  Author: momen
 */ 

#include "Include/ADC.h"

void MCAL_ADC_Init(uint8_t vref, uint8_t prescaler)
{
	ADC->ADMUX = vref;
	ADC->ADCSRA = prescaler;
	ADC_EN;
}


uint16_t MCAL_ADC_Read(uint8_t channel)
{
	ADC->ADMUX &= 0XE0;
	ADC->ADMUX |= channel;
	ADC_START;
	
	while(ADC->ADCSRA & 0X40);
	return ADC->ADCDATA;
}