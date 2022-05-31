#include<stdio.h>

void main()
{

float a [2][2];
float b [2][2];
int i,j;

printf("enter the elements of 1st matrix\n");
for (i=0;i<2;i++)
	{
	for (j=0;j<2;j++)
		{
		printf("enter a%d%d : ",i+1,j+1);
		fflush(stdin);fflush(stdout);
		scanf("%f",&a[i][j]);
		}
	}

printf("enter the elements of 2nd matrix\n");
for (i=0;i<2;i++)
	{
	for (j=0;j<2;j++)
		{
		printf("enter b%d%d : ",i+1,j+1);
		fflush(stdin);fflush(stdout);
		scanf("%f",&b[i][j]);
		}
	}

printf("sum of matrix :\n");
for (i=0;i<2;i++)
	{
	for (j=0;j<2;j++)
		{
		printf("%0.1f\t",a[i][j]+b[i][j]);
		}
	printf("\n");
	}
}
