/*
 * task2.c
 *
 * Created: 7/6/2022 8:23:41 AM
 * Author : momen
 */ 

#define PIND	*((volatile unsigned char*)0x30)
#define DDRD	*((volatile unsigned char*)0x31)
#define PORTD	*((volatile unsigned char*)0x32)

void led_switch()
{
	static int i=0, j=3;
	
	//to check if it is upwards then turn the led corresponding to location on
	if(i<3)
	{
		PORTD |= (1<<(i+5));
		i++;
		//if it reaches the end of up direction turn to down direction next time
		if(i==3) j=3;
	}
	//to check if it is downwards then turn the led corresponding to location off
	else 
	{
		if(j>0)
		{
			PORTD &= ~(1<<(j+4));
			j--;
			//if it reaches the end of down direction turn to up direction next time
			if (j==0) i=0;
		}

	}


}
int main(void)
{
    DDRD = 0b11110000;
	int f;
    while (1) 
    {
		
		//to make button1 work in single press way without blocking the other button
		if(PIND & 1)
		{
			//if button1 is pressed then check the flag if set then it's not the first time
			if(f==0)
			{
				//if button1 is pressed for the first time then set the flag for next time and toggle
				f = 1;
				led_switch();
			}
		}
				
		else
		{
			//if button1 is depressed then zero the flag
			f = 0;
		}
    }
}

