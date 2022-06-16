/*
 * main.c
 *
 *  Created on: Jun 16, 2022
 *      Author: momen amr
 */

#define SYSCTL_RCGC2_R		*((volatile unsigned int *)0x400fe108)
#define GPIO_PORTF_DIR_R	*((volatile unsigned int *)0x40025400)
#define GPIO_PORTF_DEN_R	*((volatile unsigned int *)0x4002551c)
#define GPIO_PORTF_DATA_R	*((volatile unsigned int *)0x400253fc)

void main()
{
	int i;
	SYSCTL_RCGC2_R = 0x20;
	for(i=0;i<500;i++);
	GPIO_PORTF_DIR_R |= (1<<3);
	GPIO_PORTF_DEN_R |= (1<<3);

	while (1)
	{
		GPIO_PORTF_DATA_R |= (1<<3);
		for(i=0;i<200000;i++);
		GPIO_PORTF_DATA_R &= ~(1<<3);
		for(i=0;i<200000;i++);
	}
}
