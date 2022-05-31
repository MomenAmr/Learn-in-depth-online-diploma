#include<stdio.h>

void main()
{
	float x,y,temp;
	printf("enter value of a :");
	fflush(stdin); fflush(stdout);
	scanf("%f",&x);
	printf("enter value of b :");
	fflush(stdin); fflush(stdout);
	scanf("%f",&y);
	temp = x; x = y; y = temp;
	printf("\nafter swapping, value of a = %g \nafter swapping, value of b = %g",x,y);
}
