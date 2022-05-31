#include<stdio.h>

void main()
{
	char x;

	printf("enter a character :");
	fflush(stdin); fflush(stdout);
	scanf("%c",&x);

	if ((x>64 &&x<91)||(x>96 &&x<132)) printf("%c is an alphabet",x);
	else printf("%c is not an alphabet",x);
}
