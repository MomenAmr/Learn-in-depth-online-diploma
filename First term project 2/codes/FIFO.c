/*
 * FIFO.c
 *
 *  Created on: Jun 26, 2022
 *      Author: momen
 */


#include "FIFO.h"
#include "stdio.h"
#include "string.h"


buffer_status FIFO_init(FIFO_Buffer* buffer, struct sinfo* array, int length)
{
	//this function should be called only once in the setup or the start of the program to initialize a LIFO buffer
	//based on an existing array of the same type.
	//it checks if the array is valid and put the parameters into the FIFO buffer

	if (array)
	{
		buffer->length = length;
		buffer->count = 0;
		buffer->base = array;
		buffer->head = array;
		buffer->tail = array;
		return FIFO_OK;
	}
	else return FIFO_NULL;
}

buffer_status FIFO_stat(FIFO_Buffer* buffer)
{
	//this function checks the buffer state to determine if that operations are done successfully or not

	if(!buffer || !buffer->base || !buffer->head || !buffer->tail ) return FIFO_NULL;
	if(buffer->count == buffer->length) return FIFO_FULL;
	if(buffer->count == 0) return FIFO_EMPTY;
	else return FIFO_OK;
}

buffer_status FIFO_check_duplicate(FIFO_Buffer* buffer, int roll)
{
	//this function loops through all the database entries to check if the ID entered exist already or not
	//although the implementation is not perfect since it loops on all the record, it will be called once or twice only

	int i;
	struct sinfo* p = buffer->tail;

	//this loop will work perfectly with way we use the FIFO since we don't dequeue from it then the tail and head
	//won't overlap with the end of the buffer but if we use the FIFO as intended to get elements from it then must
	//use a different loop first from tail to end and then from base to head to surf through all the elements
	for(i=0;i<buffer->count;i++)
	{
		//if any entry has the same ID as the entered data, no need to continue the loop we abort the operation altogether
		if(p->roll==roll) return FIFO_DUPLICATE_ID;
		p++;
	}

	//if the function loops through the whole buffer without finding any duplicated IDs then we can proceed
	return FIFO_OK;
}

buffer_status FIFO_update(FIFO_Buffer* buffer, int roll, int choice)
{
	//this function searches the database for an ID which when found can be updated only in one field which is
	//not perfect but is was required like this

	//checking the buffer states before operation to preserve time if it was empty then there is no entry to update
	//so we abort the operation altogether

	if(FIFO_stat(buffer) == FIFO_NULL) return FIFO_NULL;
	if(FIFO_stat(buffer) != FIFO_EMPTY)
	{
		int i;
		int x;
		struct sinfo* p = buffer->tail;

		//this loop will work perfectly with way we use the FIFO since we don't dequeue from it then the tail and head
		//won't overlap with the end of the buffer but if we use the FIFO as intended to get elements from it then must
		//use a different loop first from tail to end and then from base to head to surf through all the elements
		for(i=0;i<buffer->count;i++)
		{
			if(roll==p->roll)
			{
				//if the ID required if found then we proceed to edit only one parameter of the data
				switch(choice)
				{
				case 1:
					printf("Enter the new first name: ");
					fflush(stdin); fflush(stdout);
					gets(p->fname);
					break;
				case 2:
					printf("Enter the new last name: ");
					fflush(stdin); fflush(stdout);
					gets(p->lname);
					break;
				case 3:
					printf("Enter the new roll number: ");
					fflush(stdin); fflush(stdout);
					scanf("%d",&p->roll);
					break;
				case 4:
					printf("Enter the new GPA: ");
					fflush(stdin); fflush(stdout);
					scanf("%f",&p->GPA);
					break;
				case 5:
					printf("Enter the new courses IDs: ");
					for(x=0;x<5;x++)
						printf("Course %d ID:",i+1);
					fflush(stdin); fflush(stdout);
					scanf("%d",&p->cid[x]);
					break;
				}
				return FIFO_OK;
			}
			p++;
		}
		//if the function loops through the whole buffer without finding any matching ID then it's not in the database
		return FIFO_NO_ID;
	}
	return FIFO_EMPTY;
}

buffer_status FIFO_find(FIFO_Buffer* buffer, int roll, char* name, int cid)
{
	//this function can be used to find a record in the database using three different methods either by a roll number
	//or by a first name or by a course id
	//checking the buffer states before operation to preserve time if it was empty then there is no entry to find
	//so we abort the operation altogether

	if(FIFO_stat(buffer) == FIFO_NULL) return FIFO_NULL;
	if(FIFO_stat(buffer) != FIFO_EMPTY)
	{
		int i;
		int x;
		int y=0;
		int count=0;
		struct sinfo* p = buffer->tail;

		//this loop will work perfectly with way we use the FIFO since we don't dequeue from it then the tail and head
		//won't overlap with the end of the buffer but if we use the FIFO as intended to get elements from it then must
		//use a different loop first from tail to end and then from base to head to surf through all the elements
		for(i=0;i<buffer->count;i++)
		{
			//this function is very delicate that is checks for the method to follow so it proceeds only in one direction
			//disregarding the others so if the search is by roll number it will check for the matching between the IDs
			//if the search is by first name it will compare the entered name with the records
			//if the search is by course ID it will compare the entered ID with the all stored courses in the records
			// if an ID match if found or many name matches are found or many course matches are found it proceeds

			if (roll && p->roll==roll) y=1;
			else if (!roll && !cid && !stricmp(name,p->fname)) y=1;
			else if (cid)
			{
				for(x=0;x<5;x++)
				{
					if (cid == p->cid[x]) y = 1;
				}
			}

			if(y)
			{
				//to show the found data in the records we can divide the data into two parts, one is mutual between
				//the three methods, and another is unique to each method (if the search is by course ID then we don't
				//show all the courses for the student attending that course, or if the search is by first name we can have
				//multiple results so we continue the loop, but if the search is but roll number we break the loop
				//immediately as it's unique so there is no other matchings)

				printf("-------------------------\n");
				printf("The student details are\n");
				printf("Student first name: %s\n",p->fname);
				printf("Student last name: %s\n",p->lname);
				printf("Student roll number: %d\n",p->roll);
				printf("Student GPA number: %0.2f\n",p->GPA);

				if(!cid)
				{
					for(x=0;x<5;x++)
					{
						printf("The course ID: %d\n",p->cid[x]);
					}
					if(roll)return FIFO_OK;
				}
				//to enter another loop from the start we must zero the flag but save the count for multiple matches
				y=0;
				count ++;
			}
			p++;
		}
		//we can have two outcomes from the loop if the search is done by roll number then no ID were matching since
		//using search by roll number method will end the function if matches were found
		//but if the search is done by first name or course ID then we check for count if zero then no matches were found
		//so if count is not zero that means matches were found either by first name or course ID method so we proceed
		if(!count) return FIFO_NO_ID;
		return FIFO_OK;
	}
	return FIFO_EMPTY;
}

buffer_status FIFO_enqueue(FIFO_Buffer* buffer, struct sinfo* temp)
{
	//this function adds an entry in the database
	//checking the buffer states before operation to preserve time if it was full then there is no space to store into
	//so we abort the operation altogether

	if(FIFO_stat(buffer) == FIFO_NULL) return FIFO_NULL;
	if(FIFO_stat(buffer) != FIFO_FULL)
	{
		//checks first if the ID exist already in the database if not then proceed to enter the student data

		if(FIFO_check_duplicate(buffer,temp->roll)== FIFO_OK)
		{
			*buffer->head = *temp;
			buffer->count++;

			//to check if the FIFO buffer rolled over the array space if head reached the end and there is empty space
			//at the start to store at, but we don't use the dequeue function of the buffer so it doesn't matter we will
			//not ever roll over the buffer and seriously i don't know why we used a FIFO buffer for database if we don't
			//use if to get the data stored in order in the first place !!!!
			if ((unsigned int)buffer->head == ((unsigned int)buffer->base + (buffer->length-1)))
				buffer->head = buffer->base;
			else buffer->head++;

			return FIFO_OK;
		}
		else return FIFO_DUPLICATE_ID;
	}
	else return FIFO_FULL;
}


buffer_status FIFO_print(FIFO_Buffer* buffer)
{
	//this function shows all the entries stored in the database
	//checking the buffer states before operation to preserve time if it was empty then there is no entries to show
	//so we abort the operation altogether

	if(FIFO_stat(buffer) == FIFO_NULL) return FIFO_NULL;
	if(FIFO_stat(buffer) != FIFO_EMPTY)
	{
		printf("\n");
		int i;
		struct sinfo* p = buffer->tail;

		//simple loop through the database printing all the data for all the students as required
		//this loop will work perfectly with way we use the FIFO since we don't dequeue from it then the tail and head
		//won't overlap with the end of the buffer but if we use the FIFO as intended to get elements from it then must
		//use a different loop first from tail to end and then from base to head to surf through all the elements
		for(i=0;i<buffer->count;i++)
		{
			int x;
			printf("-------------------------\n");
			printf("Student first name: %s\n",p->fname);
			printf("Student last name: %s\n",p->lname);
			printf("Student roll number: %d\n",p->roll);
			printf("Student GPA number: %0.2f\n",p->GPA);
			for(x=0;x<5;x++)
			{
				printf("The course ID: %d\n",p->cid[x]);
			}
			p++;
		}
		return FIFO_OK;
	}
	else return FIFO_EMPTY;
}


buffer_status FIFO_delete(FIFO_Buffer* buffer, int roll)
{
	//this function deletes the entry by roll number if found in the database by a simple technique
	//checking the buffer states before operation to preserve time if it was empty then there is no entries to find
	//so we abort the operation altogether

	if(FIFO_stat(buffer) == FIFO_NULL)return FIFO_NULL;
	if(FIFO_stat(buffer) != FIFO_EMPTY)
	{
		int i;
		struct sinfo* p = buffer->tail;
		struct sinfo* temp;

		//this loop will work perfectly with way we use the FIFO since we don't dequeue from it then the tail and head
		//won't overlap with the end of the buffer but if we use the FIFO as intended to get elements from it then must
		//use a different loop first from tail to end and then from base to head to surf through all the elements
		for(i=0;i<buffer->count;i++)
		{
			if(p->roll==roll)
			{
				//if a roll number match is found we simply move all the next entries a step early overwriting the entry
				//to be deleted and also decrease the count and the buffer head by one
				for(temp=p;p<buffer->head;temp++)
				{
					*temp=*(++p);
				}

				buffer->head--;
				buffer->count--;
				return FIFO_OK;
			}
			p++;
		}
		//if the function loops through the whole buffer without finding any matching ID then it's not in the database
		return FIFO_NO_ID;
	}
	return FIFO_EMPTY;
}
