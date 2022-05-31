#include<stdio.h>

void main()
{

float a [20];
float sum=0,avg=0;
int i,n;

printf("enter the numbers of data :");
fflush(stdin);fflush(stdout);
scanf("%d",&n);

for (i=0;i<n;i++)
	{
	printf("%d. enter number : ",i+1);
	fflush(stdin);fflush(stdout);
	scanf("%f",&a[i]);
	}

for (i=0;i<n;i++)
	{
	sum+=a[i];
	}
avg=sum/n;
printf("average = %0.2f",avg);
}
