/*
 * startup.c
 *
 *  Created on: Jun 25, 2022
 *      Author: momen amr
 */

#include<stdint.h>

extern void Pressure_controller(void);
extern unsigned int _stack_top;
extern unsigned int _S_data;
extern unsigned int _E_data;
extern unsigned int _S_bss;
extern unsigned int _E_bss;
extern unsigned int _E_text;


void reset_handler(void)
{
	unsigned int data_size = (unsigned int *)&_E_data - (unsigned int *)&_S_data;
	unsigned int* P_src = (unsigned int *)&_E_text;
	unsigned int* P_dst = (unsigned int *)&_S_data;

	for(int i=0; i<data_size; i++)
	{
		*P_dst++ = *P_src++;
	}

	unsigned int bss_size = (unsigned int *)&_E_bss - (unsigned int *)&_S_bss;
	P_dst = (unsigned int *)&_S_bss;

	for(int i=0; i<bss_size; i++)
	{
		*P_dst++ = 0;
	}

	Pressure_controller();
}

void default_handler(void)
{
	reset_handler;
}

void NMI_handler(void) __attribute__ ((weak,alias ("default_handler")));;
void H_FAULT_handler(void) __attribute__ ((weak,alias ("default_handler")));;
void MM_FAULT_handler(void) __attribute__ ((weak,alias ("default_handler")));;
void BUS_FAULT_handler(void) __attribute__ ((weak,alias ("default_handler")));;
void USAGE_FAULT_handler(void) __attribute__ ((weak,alias ("default_handler")));;

uint32_t vectors[] __attribute__ ((section(".vectors")))=
{(uint32_t) & _stack_top,
 (uint32_t) & reset_handler,
 (uint32_t) & NMI_handler,
 (uint32_t) & H_FAULT_handler,
 (uint32_t) & MM_FAULT_handler,
 (uint32_t) & BUS_FAULT_handler,
 (uint32_t) & USAGE_FAULT_handler};