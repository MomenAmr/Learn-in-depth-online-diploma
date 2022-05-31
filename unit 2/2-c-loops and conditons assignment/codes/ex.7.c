#include<stdio.h>

void main()
{
	int n,fac=1;

	printf("enter an integer :");
	fflush(stdin); fflush(stdout);
	scanf("%d",&n);

	if(n<0) printf("error!!! factorial of negative numbers doesn't exist");
	else if (n==0||n==1) printf("factorial = 1");
	else
	{
		for(int i=1;i<=n;i++)
		{
			fac = fac*i;
		}
		printf("factorial = %d",fac);
	}
}
