#include<stdio.h>

void main()
{

int a[20];
int i,n,t,l;

printf("enter number of elements :");
fflush(stdin);fflush(stdout);
scanf("%d",&n);


for (i=0;i<n;i++)
	{
	a[i]=i+1;
	printf("%d ",a[i]);
	}

printf("\nenter the element to be inserted :");
fflush(stdin);fflush(stdout);
scanf("%d",&t);

printf("enter the location :");
fflush(stdin);fflush(stdout);
scanf("%d",&l);

for (i=n;i>=l;i--)
	{
	a[i]=a[i-1];
	}

a[l-1]=t;

for (i=0;i<n+1;i++)
	{
	printf("%d ",a[i]);
	}
}
