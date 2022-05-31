#include<stdio.h>

void main()
{

int a[20][20];
int t[20][20];
int i,j,r,c;

printf("enter rows and columns of matrix :");
fflush(stdin);fflush(stdout);
scanf("%d %d",&r,&c);
printf("enter elements of matrix :\n");

for (i=0;i<r;i++)
	{
	for (j=0;j<c;j++)
		{
		printf("enter element a%d%d : ",i+1,j+1);
		fflush(stdin);fflush(stdout);
		scanf("%d",&a[i][j]);
		}
	}

printf("\nentered matrix :\n");

for (i=0;i<r;i++)
	{
	for (j=0;j<c;j++)
		{
		printf("%d\t",a[i][j]);
		}
	printf("\n");
	}

for (i=0;i<r;i++)
	{
	for (j=0;j<c;j++)
		{
		t[j][i]=a[i][j];
		}
	}

printf("\ntranspose of matrix :\n");

for (i=0;i<c;i++)
	{
	for (j=0;j<r;j++)
		{
		printf("%d\t",t[i][j]);
		}
	printf("\n");
	}
}
