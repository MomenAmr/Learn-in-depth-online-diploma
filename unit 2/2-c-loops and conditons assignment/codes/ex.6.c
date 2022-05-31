#include<stdio.h>

void main()
{
	int n,sum=0;

	printf("enter an integer :");
	fflush(stdin); fflush(stdout);
	scanf("%d",&n);

	for(int i=1;i<=n;i++)
	{
		sum = sum +i;
	}

	printf("sum = %d",sum);
}
