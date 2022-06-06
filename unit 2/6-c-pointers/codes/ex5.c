
#include<stdio.h>

struct Semployee
{
	char m_name[50] ;
	int m_id;
};

void main ()
{
	struct Semployee employee1 = {"man1",1001}, employee2 = {"alex",1002}, employee3 = {"man3",1003}, employee4 = {"man4",1004}, employee5 = {"man5",1005};
	struct Semployee* pst[5] = {&employee1, &employee2, &employee3, &employee4, &employee5};
	struct Semployee* (*parr)[5] = &pst;

	printf("employee name : %s\nemployee id : %d\n",(*(*parr+1)) -> m_name,(*(*parr+1)) -> m_id);

	/*a test for a loop to access all the elements using pointer to pointer to structure*/

	int i;
	for (i=0;i<5;i++)
	{
		printf("\nemployee %d name is : %s and id is : %d",i+1,(*parr)[i]->m_name,(*parr)[i]->m_id);
	}
}
