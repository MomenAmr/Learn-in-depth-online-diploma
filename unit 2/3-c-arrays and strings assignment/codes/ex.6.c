#include<stdio.h>

void main()
{

char s[100];
int i,n=0;
char c;

printf("enter a string :");
fflush(stdin);fflush(stdout);
gets(s);

printf("enter a character to find frequency :");
fflush(stdin);fflush(stdout);
scanf("%c",&c);

for (i=0;s[i]!='\0';i++)
	{
	if(s[i]==c)
		{
		++n;
		}
	}

printf("frequency of %c is %d",c,n);
}
