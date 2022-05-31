#include<stdio.h>

void main()
{

char s[100],e[100];
int n,i,j=0;

printf("enter a string :");
fflush(stdin);fflush(stdout);
gets(s);
for (n=0;s[n]!='\0';n++);

for (i=n-1;i>=0;i--)
	{
	e[j++] = s[i];
	}
printf("reverse string is : %s",e);

}
