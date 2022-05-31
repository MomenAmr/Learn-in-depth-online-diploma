#include<stdio.h>
#include<string.h>

int Power(int x,int y)
{
if (y==0) return(1);
else return(x*Power(x,y-1));
}

void main()
{
int b,p;

printf("enter base number: ");
fflush(stdin);fflush(stdout);
scanf("%d",&b);
printf("enter power number(positive integer): ");
fflush(stdin);fflush(stdout);
scanf("%d",&p);
printf("%d ^ %d = %d",b,p,Power(b,p));
}
