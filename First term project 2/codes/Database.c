/*
 * Database.c
 *
 *  Created on: Jun 26, 2022
 *      Author: momen
 */


#include"Database.h"
#include"FIFO.h"
#include"stdio.h"

extern FIFO_Buffer buffer;

void tot_s()
{
	//checking the LIFO buffer parameters for number of elements and empty space using count and length

	printf("-------------------------\n");
	printf("[INFO] The total number of students is %d\n",buffer.count);
	printf("[INFO] You can add up to %d students\n",buffer.length);
	printf("[INFO] You can add %d more students\n",buffer.length-buffer.count);
	printf("-------------------------\n");
}

void add_student_manually()
{
	struct sinfo temp;
	int i;

	// using a straight forward approach getting the data from student bit by bit and store it in the buffer

	printf("-------------------------\nAdd the student details\n-------------------------\n");
	printf("Enter the roll number:");
	fflush(stdin); fflush(stdout);
	scanf("%d",&temp.roll);

	//this is a guard if the roll number already exist so we don't need to complete the operation to get the
	//remaining data from student, we simply send a feedback
	if (FIFO_check_duplicate(&buffer, temp.roll)==FIFO_DUPLICATE_ID)
	{
		printf("-------------------------\n");
		printf("[ERROR]  Roll number %d is already taken\n",temp.roll);
		printf("-------------------------\n");
	}

	//if the roll number is unique then we proceed to get the remaining data from student
	else
	{
		printf("Enter the first name of student:");
		fflush(stdin); fflush(stdout);
		gets(temp.fname);
		printf("Enter the last name of student:");
		fflush(stdin); fflush(stdout);
		gets(temp.lname);
		printf("Enter the GPA you obtained:");
		fflush(stdin); fflush(stdout);
		scanf("%f",&temp.GPA);

		printf("Enter the course ID of each course\n");
		for(i=0;i<5;i++)
		{
			printf("Course %d ID:",i+1);
			fflush(stdin); fflush(stdout);
			scanf("%d",&temp.cid[i]);
		}

		//calling the function to store the data into the buffer inside a switch body so we can use the buffer states as
		//feedback to output for the student if the operation succeeded or not and the type of error if occurs

		switch (FIFO_enqueue(&buffer,&temp))
		{
		case FIFO_FULL:
			printf("-------------------------\n");
			printf("[ERROR]  Students database is full\n");
			printf("-------------------------\n");
			break;
		case FIFO_OK:
			printf("-------------------------\n");
			printf("[INFO]  Student details was added successfully\n");
			printf("-------------------------\n");
			break;
		default:
			printf("-------------------------\n");
			printf("[INFO]  Buffer is not initialized properly\n");
			printf("-------------------------\n");
		}

		//as required to show the total number of students after each successful student entry

		tot_s();
	}

}

void add_student_file()
{
	int count;
	struct sinfo temp;
	FILE* fp = fopen("students.txt","r");

	//it's a simple way to use fopen, fscan ,and fclose to read from file the data stored in a certain way

	if(fp)
	{
		while(fscanf(fp,"%d %s %s %f %d %d %d %d %d",&temp.roll,temp.fname,temp.lname,&temp.GPA,
				&temp.cid[0] ,&temp.cid[1],&temp.cid[2],&temp.cid[3],&temp.cid[4])!=EOF)
		{
			//calling the function to store the data into the buffer inside a switch body so we can use the buffer states as
			//feedback to output for the student if the operation succeeded or not and the type of error if occurs

			switch (FIFO_enqueue(&buffer,&temp))
			{
			case FIFO_FULL:
				printf("[ERROR]  Students database is full\n");
				break;
			case FIFO_OK:
				printf("[INFO]  Roll number %d was saved successfully\n",temp.roll);
				count++;
				break;
			case FIFO_DUPLICATE_ID:
				printf("[ERROR]  Roll number %d is already taken\n",temp.roll);
				break;
			default:
				printf("[INFO]  Buffer is not initialized properly\n");
			}
		}

		//using count as an easy way to check if any entry was stored successfully from the file guarding from wrong
		//massage if all the entry from the file got rejected

		if(count) printf("[INFO]  Student details was added successfully\n");

		//as required to show the total number of students after each successful student entry

		tot_s();
		fclose(fp);
	}

	else
	{
		printf("-------------------------\n");
		printf("[ERROR]  Students.text can't be opened\n");
		printf("-------------------------\n");
	}
}

void show_s()
{
	//calling the function to print all the data stored in the buffer inside a switch body so we can use the buffer states
	//as feedback to output for the student if the operation succeeded or not and the type of error if occurs

	switch (FIFO_print(&buffer))
	{
	case FIFO_EMPTY:
		printf("-------------------------\n");
		printf("[ERROR]  Students database is empty\n");
		printf("-------------------------\n");
		break;
	case FIFO_OK:
		printf("-------------------------\n");
		break;
	default:
		printf("-------------------------\n");
		printf("[INFO]  Buffer is not initialized properly\n");
		printf("-------------------------\n");
	}

}

void find_rl()
{
	int roll;

	//getting the roll number that will be checked against the database entries from the student

	printf("Enter the roll number of the student:");
	fflush(stdin); fflush(stdout);
	scanf("%d",&roll);

	//calling the function to check the data stored in the buffer inside a switch body so we can use the buffer states as
	//feedback to output for the student if the operation succeeded or not and the type of error if occurs

	switch(FIFO_find(&buffer,roll,NULL,0))
	{
	case FIFO_NO_ID:
		printf("-------------------------\n");
		printf("[ERROR]  Roll number %d was not found\n",roll);
		printf("-------------------------\n");
		break;
	case FIFO_EMPTY:
		printf("-------------------------\n");
		printf("[ERROR]  Students database is empty\n");
		printf("-------------------------\n");
		break;
	case FIFO_OK:
		printf("-------------------------\n");
		break;
	default:
		printf("-------------------------\n");
		printf("[INFO]  Buffer is not initialized properly\n");
		printf("-------------------------\n");
	}
}

void find_fn()
{
	char name[50];

	//getting the first name that will be checked against the database entries from the student

	printf("Enter the first name of the student:");
	fflush(stdin); fflush(stdout);
	gets(name);

	//calling the function to check the data stored in the buffer inside a switch body so we can use the buffer states as
	//feedback to output for the student if the operation succeeded or not and the type of error if occurs

	switch(FIFO_find(&buffer,0,name,0))
	{
	case FIFO_NO_ID:
		printf("-------------------------\n");
		printf("[ERROR]  First name %s was not found\n",name);
		printf("-------------------------\n");
		break;
	case FIFO_EMPTY:
		printf("-------------------------\n");
		printf("[ERROR]  Students database is empty\n");
		printf("-------------------------\n");
		break;
	case FIFO_OK:
		printf("-------------------------\n");
		break;
	default:
		printf("-------------------------\n");
		printf("[INFO]  Buffer is not initialized properly\n");
		printf("-------------------------\n");
	}
}

void find_c()
{
	int cid;

	//getting the course ID that will be checked against the database entries from the student

	printf("Enter the course ID:");
	fflush(stdin); fflush(stdout);
	scanf("%d",&cid);

	//calling the function to check the data stored in the buffer inside a switch body so we can use the buffer states as
	//feedback to output for the student if the operation succeeded or not and the type of error if occurs

	switch(FIFO_find(&buffer,0,NULL,cid))
	{
	case FIFO_NO_ID:
		printf("-------------------------\n");
		printf("[ERROR]  Course ID %d was not found\n",cid);
		printf("-------------------------\n");
		break;
	case FIFO_EMPTY:
		printf("-------------------------\n");
		printf("[ERROR]  Students database is empty\n");
		printf("-------------------------\n");
		break;
	case FIFO_OK:
		printf("-------------------------\n");
		break;
	default:
		printf("-------------------------\n");
		printf("[INFO]  Buffer is not initialized properly\n");
		printf("-------------------------\n");
	}
}

void up_s()
{
	int roll;
	int choice;

	//getting the roll number that will be checked against the database entries from the student

	printf("Enter the roll number of the student:");
	fflush(stdin); fflush(stdout);
	scanf("%d",&roll);

	//this is a guard if the roll number doesn't exist so we don't need to complete the operation to get the
	//remaining data from student, we simply send a feedback
	if (FIFO_check_duplicate(&buffer,roll)==FIFO_OK)
	{
		printf("-------------------------\n");
		printf("[ERROR]  Roll number %d was not found\n",roll);
		printf("-------------------------\n");
	}

	//if the roll number is found then we proceed to get the remaining data from student
	else
	{
		//a simple loop guarding from entering wrong options. although the method of execution for this function is not perfect,
		//the project video demanded it to be done like showed so i adhered to what was asked

		while(1)
		{
			printf("1. first name\n2. last name\n3. roll number\n4. GPA\n5. courses\n");
			fflush(stdin); fflush(stdout);
			scanf("%d",&choice);
			if(choice==1 || choice==2 || choice==3 || choice==4 || choice==5) break;
			printf("please enter a valid option !!\n");
		}

		//calling the function to update one student data stored in the buffer inside a switch body so we can use the buffer
		//states as feedback to output for the student if the operation succeeded or not and the type of error if occurs

		switch(FIFO_update(&buffer,roll,choice))
		{
		case FIFO_EMPTY:
			printf("-------------------------\n");
			printf("[ERROR]  Students database is empty\n");
			printf("-------------------------\n");
			break;
		case FIFO_OK:
			printf("-------------------------\n");
			printf("[INFO]  Updated successfully\n");
			printf("-------------------------\n");
			break;
		default:
			printf("-------------------------\n");
			printf("[INFO]  Buffer is not initialized properly\n");
			printf("-------------------------\n");
		}
	}
}

void del_s()
{
	int roll;

	//getting the roll number that will be checked against the database entries from the student

	printf("Enter the roll number which you want to delete:");
	fflush(stdin); fflush(stdout);
	scanf("%d",&roll);

	//calling the function to delete one student data stored in the buffer inside a switch body so we can use the buffer
	//states as feedback to output for the student if the operation succeeded or not and the type of error if occurs

	switch(FIFO_delete(&buffer,roll))
	{
	case FIFO_NO_ID:
		printf("-------------------------\n");
		printf("[ERROR]  Roll number %d was not found\n",roll);
		printf("-------------------------\n");
		break;
	case FIFO_EMPTY:
		printf("-------------------------\n");
		printf("[ERROR]  Students database is empty\n");
		printf("-------------------------\n");
		break;
	case FIFO_OK:
		printf("-------------------------\n");
		printf("[INFO]  The roll number was removed successfully\n");
		printf("-------------------------\n");
		break;
	default:
		printf("-------------------------\n");
		printf("[INFO]  Buffer is not initialized properly\n");
		printf("-------------------------\n");
	}
}
