/*
 * GccApplication1.c
 *
 * Created: 7/4/2022 11:05:50 AM
 * Author : momen
 */ 

#define F_CPU 8000000UL

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

int main(void)
{
    DDRD |= 0b11100000;
	MCUCR |= 0b00001101;
	MCUCSR &= 0b10111111;
	GICR |= 0b11100000;
	
	sei();
	
    while (1);
}

ISR(INT0_vect)
{
	PORTD |= 0b00100000;
	_delay_ms(1000);
	PORTD &= 0b11011111;
}

ISR(INT1_vect)
{
	PORTD |= 0b01000000;
	_delay_ms(1000);
	PORTD &= 0b10111111;
}

ISR(INT2_vect)
{
	PORTD |= 0b10000000;
	_delay_ms(1000);
	PORTD &= 0b01111111;
}