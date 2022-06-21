/*
 * LINKED_LIST.c
 *
 *  Created on: Jun 19, 2022
 *      Author: momen
 */


#include "LINKED_LIST.h"

void student_add(struct Sstudent** list)
{
	struct Sstudent* p_new_student;
	struct Sstudent* p_last_student;

	if(*list == NULL)
	{
		p_new_student= malloc(sizeof(struct Sstudent));
		*list = p_new_student;
	}
	else
	{
		p_last_student = *list;
		while(p_last_student->next_student)
		{
			p_last_student = p_last_student->next_student;
		}
		p_new_student= malloc(sizeof(struct Sstudent));
		p_last_student->next_student = p_new_student;
	}

	student_fill_data(p_new_student);
	p_new_student->next_student = NULL;

}

void student_fill_data(struct Sstudent* student)
{
	int i;
	float h;

	printf("\nenter the ID: ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&i);
	student->student.ID = i;

	printf("enter the name: ");
	fflush(stdin); fflush(stdout);
	gets(student->student.name);

	printf("enter the height: ");
	fflush(stdin); fflush(stdout);
	scanf("%f",&h);
	student->student.height = h;

}

void student_delete(struct Sstudent** list, int ID)
{
	if(*list == NULL) printf("\nthe list is empty !!!\n");

	else
	{
		struct Sstudent* p_prev_student = NULL;
		struct Sstudent* p_curr_student = *list;
		while(p_curr_student)
		{
			if(p_curr_student->student.ID == ID)
			{
				if(p_prev_student) p_prev_student->next_student = p_curr_student->next_student;
				else *list = p_curr_student->next_student;
				free(p_curr_student);
				break;
			}
			p_prev_student = p_curr_student;
			p_curr_student = p_curr_student->next_student;

		}
		if(p_curr_student) printf("\nthe ID: %d is deleted !!!\n", ID);
		else printf("\nthe ID is not found !!!\n");
	}
}

void student_find(struct Sstudent** list, int index)
{
	if(*list == NULL) printf("\nthe list is empty !!!\n");
	if(index >= list_len( list)) printf("\nthe index exceeds the list length !!!\n");
	else
	{
		int i=0;
		struct Sstudent* p_curr_student = *list;

		while (i<index)
		{
			p_curr_student = p_curr_student->next_student;
			i++;
		}
		printf("\nID: %d\nname: %s\nheight: %f\n", p_curr_student->student.ID, p_curr_student->student.name, p_curr_student->student.height);
	}
}

void list_view(struct Sstudent** list)
{
	if(*list == NULL) printf("\nthe list is empty !!!\n");

	else
	{
		int i=1;
		struct Sstudent* p_last_student = *list;
		while(p_last_student)
		{
			printf("\nrecord number: %d\nID: %d\nname: %s\nheight: %f\n",i, p_last_student->student.ID, p_last_student->student.name, p_last_student->student.height);
			p_last_student = p_last_student->next_student;
			i++;
		}
	}
}

void list_delete(struct Sstudent** list)
{
	if(*list == NULL) printf("\nthe list is empty !!!\n");

	else
	{
		struct Sstudent* p_curr_student = *list;
		while(p_curr_student)
		{
			struct Sstudent* p_temp = p_curr_student;
			p_curr_student = p_curr_student->next_student;
			free(p_temp);
		}
		*list = NULL;
		printf("\nthe list is empty !!!\n");
	}
}

void list_reverse(struct Sstudent** list)
{
	if(*list == NULL) printf("\nthe list is empty !!!\n");
	else
	{
		struct Sstudent* p_curr_student = *list;
		struct Sstudent* p_prev_student = NULL;
		struct Sstudent* p_next_student = NULL;
		while(p_curr_student)
		{
			p_next_student = p_curr_student->next_student;
			p_curr_student->next_student=p_prev_student;
			p_prev_student = p_curr_student;
			p_curr_student = p_next_student;
		}
		* list = p_prev_student;
		printf("\nthe list is successfully reversed !!!\n");
	}
}

void list_middle(struct Sstudent** list)
{
	if(*list == NULL) printf("\nthe list is empty !!!\n");
	else
	{
		int i=0;
		struct Sstudent* p_end_student = *list;
		struct Sstudent* p_middle_student = *list;

		while(p_end_student)
		{
			p_end_student = p_end_student->next_student;

			if(i==1)
				{
				p_middle_student =p_middle_student->next_student;
				i=0;
				}
			else i=1;
		}
		printf("\nID: %d\nname: %s\nheight: %f\n", p_middle_student->student.ID, p_middle_student->student.name, p_middle_student->student.height);
	}
}

int list_len(struct Sstudent** list)
{
	if(*list == NULL) return 0;
	else
	{
		int i=0;
		struct Sstudent* p_curr_student = *list;

		while(p_curr_student)
		{
			p_curr_student = p_curr_student->next_student;
			i++;
		}
		return i;
	}
}
