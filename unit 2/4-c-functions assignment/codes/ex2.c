#include<stdio.h>

int GetFact (int x)
{
if (x==1) return(1);
else x*=GetFact(x-1);
}

void main()
{
int i;

printf("enter a positive integer: ");
fflush(stdin);fflush(stdout);
scanf("%d",&i);

printf("factorial of %d = %d",i,GetFact(i));
}
