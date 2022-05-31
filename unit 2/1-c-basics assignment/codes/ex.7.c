#include<stdio.h>

void main()
{
	float x,y;
	printf("enter value of a :");
	fflush(stdin); fflush(stdout);
	scanf("%f",&x);
	printf("enter value of b :");
	fflush(stdin); fflush(stdout);
	scanf("%f",&y);
	x = y-x; y = y-x; x = x+y;
	printf("\nafter swapping, value of a = %g \nafter swapping, value of b = %g",x,y);
}
