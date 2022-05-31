#include<stdio.h>

void main()
{

int a[20];
int i,n,s;

printf("enter number of elements :");
fflush(stdin);fflush(stdout);
scanf("%d",&n);


for (i=0;i<n;i++)
	{
	a[i]=(i+1)*11;
	printf("%d ",a[i]);
	}

printf("\nenter the element to be searched :");
fflush(stdin);fflush(stdout);
scanf("%d",&s);

for (i=0;i<n;i++)
	{
	if(a[i]==s)
		{
		printf("number found at location : %d",i+1);
		break;
		}
	if(i==n-1)
		{
		printf("number can't be found");
		}
	}
}
