/*
 * USART.h
 *
 * Created: 7/18/2022 1:07:47 PM
 *  Author: momen
 */ 


#ifndef USART_H_
#define USART_H_

//-----------------------------------------------------------------------------------
//includes
//-----------------------------------------------------------------------------------

#include "atmega32a_device_header.h"
#include "FIFO.h"
 #include <avr\interrupt.h>

//===================================================================================

//-----------------------------------------------------------------------------------
//Macros configuration references
//-----------------------------------------------------------------------------------

//@ref USART pins
#define UCSZ2 				2
#define TXEN				3
#define RXEN 				4
#define UDRIE				5
#define RXCIE				7


#define U2X 				1
#define UDRE				5
#define RXC 				7

#define UCSZ0 				1
#define UCSZ1 				2
#define USBS				3
#define UPM0 				4
#define UPM1				5
#define UMSEL 				6
#define URSEL 				7

#define RD_BIT(reg,bit)		(reg & (1<<bit))
#define SET_BIT(reg,bit)	(reg |= (1<<bit))
#define CLR_BIT(reg,bit)	(reg &=~ (1<<bit))

//===================================================================================

//-----------------------------------------------------------------------------------
//APIs supported by MCAL GPIO driver
//-----------------------------------------------------------------------------------

void MCAL_USART_Init ();

void MCAL_USART_SEND_CHAR (char data);
char MCAL_USART_RECV_CHAR ();
void MCAL_USART_SEND_INT (int data);
int MCAL_USART_RECV_INT ();
void MCAL_USART_SEND_STR (char* data);
char* MCAL_USART_RECV_STR (char* data);

 void UART_RX_IRQ_EN(void);
 void UART_RX_IRQ_DIS(void);
 void UART_TX_IRQ_EN(void);
 void UART_TX_IRQ_DIS(void);



//===================================================================================
#endif /* USART_H_ */