#include<stdio.h>

struct Sstudent
{
	char m_name[50];
	int m_roll;
	float m_mark;
};

void main ()
{
	struct Sstudent x[10];
	int i;

	printf("enter information of students\n");

	for(i=0;i<10;i++)
	{
		printf("\nfor roll number %d:\n",x[i].m_roll=i+1);

		printf("enter name:");
		fflush(stdin);fflush(stdout);
		gets(x[i].m_name);

		printf("enter marks:");
		fflush(stdin);fflush(stdout);
		scanf("%f",&x[i].m_mark);
	}

	printf("\ndisplaying information of students\n");

	for(i=0;i<10;i++)
	{
		printf("\ninformation for roll number %d:\nname: %s\nmarks: %0.2f\n",x[i].m_roll,x[i].m_name,x[i].m_mark);
	}
}
