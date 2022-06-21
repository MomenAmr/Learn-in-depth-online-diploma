/*
 * main.c
 *
 *  Created on: Jun 19, 2022
 *      Author: momen
 */


#include "LINKED_LIST.h"

struct Sstudent*  gp_student_list = NULL;

void main()
{
	while(1)
	{
		int x;
		printf("\nwhat operation do you wish to execute on list?\n  1-add student to list\n  2-delete student from list\n  3-find student\n  4-display list\n  5-delete list\n  6-reverse list\n  7-list middle\n  8-list length\n  9-terminate program\nyour choise is:");
		fflush(stdin); fflush(stdout);
		scanf("%d",&x);

		if(x==1)
		{
			student_add(&gp_student_list);
		}

		else if(x==2)
		{
			int i;
			printf("\nenter ID to be deleted from list:");
			fflush(stdin); fflush(stdout);
			scanf("%d",&i);
			student_delete(&gp_student_list,i);
		}

		else if(x==3)
		{
			int i;
			printf("\nenter index to be displayed:");
			fflush(stdin); fflush(stdout);
			scanf("%d",&i);
			student_find(&gp_student_list,i);
		}

		else if(x==4)
		{
			list_view(&gp_student_list);
		}

		else if(x==5)
		{
			list_delete(&gp_student_list);
		}

		else if(x==6)
		{
			list_reverse(&gp_student_list);
		}

		else if(x==7)
		{
			list_middle(&gp_student_list);
		}

		else if(x==8)
		{
			printf("\nlist length is %d\n",list_len(&gp_student_list));
		}

		else if(x==9)
		{
			printf("program is terminated !!");;
			break;
		}

		else
		{
			printf("please enter a valid option !!");
		}
	}
}

