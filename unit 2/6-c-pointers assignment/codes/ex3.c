#include<stdio.h>

void main ()
{
	char str[100];
	char* pa = str;
	int i=0;

	printf("Pointer : Print a string in reverse order :\n----------------------------------------------------\n");
	printf("input a string : ");
	fflush(stdin);fflush(stdout);
	gets(str);

	while(str[i]!='\0')i++;

	printf("reverse of the string is : ");
	for (i--;i>=0;i--)
	{
		printf("%c",*(pa+i));
	}
}
