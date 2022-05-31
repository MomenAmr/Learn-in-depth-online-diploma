#include<stdio.h>

void main()
{
	float x,max=0;

	printf("enter three numbers :");
	fflush(stdin); fflush(stdout);

	for(int i=0;i<3;i++)
	{
		scanf("%f",&x);
		if (x>max) max = x;
	}

	printf("largest number is %0.2f",max);
}
