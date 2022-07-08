/*
 * lab2.c
 *
 * Created: 7/6/2022 8:23:41 AM
 * Author : momen
 */ 

#define DDRD	*((volatile unsigned char*)0x31)
#define PORTD	*((volatile unsigned char*)0x32)


void delay_loop(int x)
{
	int i,j;
	for(i=0;i<x;i++) for(j=0;j<600;j++);
}


int main(void)
{
    DDRD = 0b11110000;
	int i;
    while (1) 
    {
		for(i=0;i<3;i++)
		{
			PORTD = (1<<(i+5));
			delay_loop(1000);
		}
		
		PORTD = 0b00010000;
		delay_loop(1000);		
    }
}

