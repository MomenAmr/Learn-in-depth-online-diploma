#include<stdio.h>

void main()
{
	char x;
	printf("enter a character :");
	fflush(stdin); fflush(stdout);
	scanf("%c",&x);
	printf("ASCII value of %c is %d",x,x);
}
