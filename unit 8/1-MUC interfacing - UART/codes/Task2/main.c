/*
 * LCD_Keypad_atmega32.c
 *
 * Created: 7/7/2022 1:17:05 PM
 * Author : momen
 */ 

#define	F_CPU 8000000UL
#include <util/delay.h>
#include "include/LCD.h"
#include "Include/USART.h"

volatile char buffer[100];
FIFO_Buffer UART_buffer = {96,0,buffer,buffer,buffer};

 void UART_STORE_IRQ ()
 {
	 if(UART_buffer.count == UART_buffer.length) UART_RX_IRQ_DIS();

	 else
	 {
		 char c = UDR;
		 
		 if(c != 0x0D) FIFO_enqueue(&UART_buffer, c);
		 
		 else UART_TX_IRQ_EN();
	 }
	 
 }
 
 void UART_TRANS_IRQ ()
 {
	 if(UART_buffer.count == 0) UART_TX_IRQ_DIS();
	 
	 else
	 {
		 static int p=0;
		 char c;
		 FIFO_dequeue(&UART_buffer, &c);
		 UDR = c;
		 
		 LCD_send_command(LCD_BEGIN_AT_FIRST_ROW + p);
		 LCD_send_data(c);
		 ++p;
		 if(p==16)
		 {
			 LCD_send_command(LCD_CLEAR_SCREEN);
			 p=0;
		 }
	 }
 }
 
ISR(USART_RXC_vect)
{
	UART_STORE_IRQ ();
}

ISR(USART_UDRE_vect)
{
	UART_TRANS_IRQ();
}

int main(void)
{
	LCD_init();
	LCD_send_string("LCD initialized");
	LCD_send_command(LCD_BEGIN_AT_SECOND_ROW);
	LCD_send_string("perfectly");
	
	MCAL_USART_Init();
	MCAL_USART_SEND_STR("UART initialized and working perfectly!");
	
	wait_loop(1000);
	LCD_send_command(LCD_CLEAR_SCREEN);
	
	UART_RX_IRQ_EN();
	UART_TX_IRQ_EN();
	sei();

	volatile char x = '0';
	while (1) 
    {
		LCD_send_command(LCD_BEGIN_AT_SECOND_ROW);
		LCD_send_data(x);
		
		x++;
		if(x == '9') x = '0';
		_delay_ms(200);
	}
}

