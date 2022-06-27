/*
 * main.c
 *
 *  Created on: Jun 19, 2022
 *      Author: momen
 */


#include "stdio.h"
#include "Database.h"
#include "FIFO.h"

FIFO_Buffer buffer;

void main()
{
	//initialize the FIFO buffer with the global array
	FIFO_init(&buffer, st, 50);

	int x;
	printf("Welcome to the student management system\n");

	//this loop acts as the program to execute the operations required
	while(1)
	{
		printf("Choose the task that you want to perform\n");
		printf(" 1. Add the student details manually\n");
		printf(" 2. Add the student details from text file\n");
		printf(" 3. Find the student details by roll number\n");
		printf(" 4. Find the student details by first name\n");
		printf(" 5. Find the student details by course ID\n");
		printf(" 6. Find the total number of students\n");
		printf(" 7. Delete the student details by roll number\n");
		printf(" 8. Update the student details by roll number\n");
		printf(" 9. Show all information\n");
		printf("10. Exit\n");
		printf("Enter your choice to perform the task:");
		fflush(stdin); fflush(stdout);
		scanf("%d",&x);

		//i know the switch statement is better in this situation but i used it much in the functions so i used if here

		if(x==1)
		{
			add_student_manually();
		}

		else if(x==2)
		{
			add_student_file();
		}

		else if(x==3)
		{
			find_rl();
		}

		else if(x==4)
		{
			find_fn();
		}

		else if(x==5)
		{
			find_c();
		}

		else if(x==6)
		{
			tot_s();
		}

		else if(x==7)
		{
			del_s();
		}


		else if (x==8)
		{
			up_s();
		}

		else if (x==9)
		{
			show_s();
		}

		else if (x==10)
		{
			printf("program is terminated !!");;
			break;
		}

		else
		{
			printf("please enter a valid option !!\n");
		}

	}
}
