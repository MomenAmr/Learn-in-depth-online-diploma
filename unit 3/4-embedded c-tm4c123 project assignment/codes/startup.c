/*
 * startup.c
 *
 *  Created on: Jun 16, 2022
 *      Author: momen amr
 */

extern int main(void);
extern unsigned int _S_data;
extern unsigned int _E_data;
extern unsigned int _S_bss;
extern unsigned int _E_bss;
extern unsigned int _E_text;
static unsigned int stack_top[256];

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

	main();
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

void (*const vectors[])() __attribute__ ((section(".vectors")))=
{(void (*)())((unsigned int)stack_top + sizeof(stack_top)),
 & reset_handler,
 & NMI_handler,
 & H_FAULT_handler,
 & MM_FAULT_handler,
 & BUS_FAULT_handler,
 & USAGE_FAULT_handler};