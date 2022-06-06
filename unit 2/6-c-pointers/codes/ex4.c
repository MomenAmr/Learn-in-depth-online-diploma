#include<stdio.h>

void main ()
{
	int arr[15];
	int* pa = arr;
	int i,n;

	printf("input the number of elements to store in the array (max 15) :");
	fflush(stdin);fflush(stdout);
	scanf("%d",&n);

	printf("\ninput %d number of elements in the array :\n",n);
	for (i=0;i<n;i++)
	{
		printf("element-%d : ",i+1);
		fflush(stdin);fflush(stdout);
		scanf("%d",pa++);
	}

	pa = arr + n - 1;
	printf("The elements of array in reverse order are :\n");
	for (i=n;i>0;i--)
	{
		printf("element-%d : %d\n",i,*pa--);
	}
}
