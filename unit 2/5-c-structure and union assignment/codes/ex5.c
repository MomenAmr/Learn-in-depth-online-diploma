#include<stdio.h>
#define area(x) 3.14159*x*x

void main ()
{
	int x;

	printf("enter the radius:");
	fflush(stdin);fflush(stdout);
	scanf("%d",&x);

	printf("area = %0.2lf",area(x));
}
