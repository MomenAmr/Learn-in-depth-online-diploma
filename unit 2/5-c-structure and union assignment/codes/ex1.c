#include<stdio.h>

struct Sstudent
{
	char m_name[50];
	int m_roll;
	float m_mark;
};

void main ()
{
	struct Sstudent x;

	printf("enter information of student:\n\n");
	printf("enter name:");
	fflush(stdin);fflush(stdout);
	gets(x.m_name);

	printf("enter roll number:");
	fflush(stdin);fflush(stdout);
	scanf("%d",&x.m_roll);

	printf("enter marks:");
	fflush(stdin);fflush(stdout);
	scanf("%f",&x.m_mark);

	printf("\ndisplaying information\nname: %s\nroll: %d\nmarks: %0.2f",x.m_name,x.m_roll,x.m_mark);
}
