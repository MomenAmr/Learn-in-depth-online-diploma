#include<stdio.h>

void main()
{

char s[100];
int i;

printf("enter a string :");
fflush(stdin);fflush(stdout);
gets(s);

for (i=0;s[i]!='\0';i++);
printf("length of string : %d",i);

}
