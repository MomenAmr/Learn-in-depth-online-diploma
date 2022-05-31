#include<stdio.h>

int CheckPrime (int x)
{
	if (x==1 || x==2 || x==3 || x==5 || x==7 ||((x%2 && x%3 && x%5 && x%7)!=0)) return(1);
	else return(0);
}

void main()
{
int min,max,i;

printf("enter two numbers(intervals) : ");
fflush(stdin);fflush(stdout);
scanf("%d %d",&min,&max);

printf("prime numbers between %d and %d are : ",min,max);

for(i=min+1;i<max;i++)
	{
	if (CheckPrime(i)) printf("%d ",i);
	}
}
