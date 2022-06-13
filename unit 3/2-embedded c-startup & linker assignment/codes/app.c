/*
 * app.c
 *
 *  Created on: Jun 12, 2022
 *      Author: momen amr
 */

#include<UART.h>

unsigned char string_buffer[100] = "Learn_in_depth : <Mo'men Amr>";

void main(void)
{
	Uart_Send_String(string_buffer);
}