#include<stdio.h>

union job1
{	char name[30];
	float salary;
	int worker_no;
}u;

struct job2
{	char name[30];
	float salary;
	int worker_no;
}s;

void main ()
{
	printf("size of union = %d",sizeof(u));
	printf("\nsize of structure = %d",sizeof(s));
}
