/*
 * task3.c
 *
 * Created: 7/6/2022 8:23:41 AM
 * Author : momen
 */ 

#define DDRC	*((volatile unsigned char*)0x34)
#define PORTC	*((volatile unsigned char*)0x35)


void delay_loop(int x)
{
	int i,j;
	for(i=0;i<x;i++) for(j=0;j<1000;j++);
}


int main(void)
{
    DDRC = 0xff;
	int i,j,k;
    while (1) 
    {
		for(i=0;i<10;i++)
		{
			for(j=0;j<10;j++)
			{
				for (k=0;k<10;k++)
				{
					
					PORTC = (0b0100|(j<<4));
					delay_loop(10);
					PORTC = 0;
					
					PORTC = (0b1000|(i<<4));
					delay_loop(10);
					PORTC = 0;
				}

			}
		}
		
    }
}

