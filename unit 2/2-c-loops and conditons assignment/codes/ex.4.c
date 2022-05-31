#include<stdio.h>

void main()
{
	float x;

	printf("enter a number :");
	fflush(stdin); fflush(stdout);
	scanf("%f",&x);

	if (x==0) printf("you entered zero");
	else if (x>0) printf("%0.2f is positive",x);
	else printf("%0.2f is negative",x);
}
