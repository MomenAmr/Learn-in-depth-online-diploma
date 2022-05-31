#include<stdio.h>
#include<string.h>

void PrintReverse(char arr[],int n)
{
if(n>=0)
	{
	printf("%c",arr[n]);
	(PrintReverse(arr,n-1));
	}
}

void main()
{
char s[100];

printf("enter a sentence: ");
fflush(stdin);fflush(stdout);
gets(s);
PrintReverse(s,strlen(s)-1);
}
