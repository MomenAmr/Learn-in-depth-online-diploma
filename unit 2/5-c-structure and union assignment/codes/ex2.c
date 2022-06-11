#include<stdio.h>

struct Sdistance
{
	int m_feet;
	float m_inches;
};

void main ()
{
	struct Sdistance x,y,z;

	printf("enter information for 1st distance:\n");
	printf("enter feet:");
	fflush(stdin);fflush(stdout);
	scanf("%d",&x.m_feet);

	printf("enter inches:");
	fflush(stdin);fflush(stdout);
	scanf("%f",&x.m_inches);

	printf("\nenter information for 2nd distance:\n");
	printf("enter feet:");
	fflush(stdin);fflush(stdout);
	scanf("%d",&y.m_feet);

	printf("enter inches:");
	fflush(stdin);fflush(stdout);
	scanf("%f",&y.m_inches);

	z.m_feet = x.m_feet + y.m_feet;
	z.m_inches = x.m_inches + y.m_inches;

	if (z.m_inches >= 12){z.m_inches-=12; z.m_feet+=1;}
	printf("\nsum of distances = %d'%0.2f",z.m_feet,z.m_inches);
}
