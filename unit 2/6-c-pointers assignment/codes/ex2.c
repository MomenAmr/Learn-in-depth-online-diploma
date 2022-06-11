#include<stdio.h>

void main ()
{
	/*char alpha[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";*/
	char alpha[27];
	char* pa = alpha;
	int i;

	for (i=0;i<26;i++)
	{
		*(pa+i) ='A'+i;
	}

	printf("the alphabets are:\n");

	for (i=0;i<26;i++)
	{
		printf(" %c",*pa++);
	}
}
