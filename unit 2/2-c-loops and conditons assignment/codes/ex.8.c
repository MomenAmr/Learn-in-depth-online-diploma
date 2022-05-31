#include<stdio.h>

void main()
{
	char op;
	float x,y;

	printf("enter operator either + or - or * or / :");
	fflush(stdin); fflush(stdout);
	scanf("%c",&op);
	printf("enter two operands:");
	fflush(stdin); fflush(stdout);
	scanf("%f %f",&x,&y);

	switch(op)
	{
	case '+':
	{printf("%0.1f %c %0.1f = %0.1f",x,op,y,x+y);}
	break;
	case '-':
	{printf("%0.1f %c %0.1f = %0.1f",x,op,y,x-y);}
	break;
	case '*':
	{printf("%0.1f %c %0.1f = %0.1f",x,op,y,x*y);}
	break;
	case '/':
	{printf("%0.1f %c %0.1f = %0.1f",x,op,y,x/y);}
	break;
	}
}
