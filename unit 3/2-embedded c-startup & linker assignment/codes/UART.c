/*
 * UART.c
 *
 *  Created on: Jun 12, 2022
 *      Author: momen amr
 */

#include<UART.h>
#define UART0DR *((volatile unsigned int *const)((unsigned int *)0x101f1000))

void Uart_Send_String(unsigned char *P_tx_string)
{
	while(*P_tx_string != '\0')
	{
	UART0DR = *P_tx_string;
	P_tx_string++;
	}
}