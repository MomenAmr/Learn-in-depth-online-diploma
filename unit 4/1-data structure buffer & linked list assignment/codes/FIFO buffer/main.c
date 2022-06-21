/*
 * main.c
 *
 *  Created on: Jun 19, 2022
 *      Author: momen
 */


#include "stdio.h"
#include "FIFO.h"

unsigned int arr[20];

void main()
{

	FIFO_Buffer_32 buffer = {5,0,arr,arr,arr};

	while(1)
	{
		int x;
		printf("\nwhat operation do you wish to execute on queue?\n	0-check queue status\n	1-display queue\n	2-add element to queue\n	3-get element from queue\n	4-erase queue\n	5-terminate program\nyour choise is:");
		fflush(stdin); fflush(stdout);
		scanf("%d",&x);

		if(x==0)
		{
			int i = FIFO_stat(&buffer,32);

			if (i==0)
			{
				printf("\nthe queue could not be successfully established !!!\n");
			}

			else if(i==1)
			{
				printf("\nthe queue worked successfully !!!\n");
			}

			else if(i==2)
			{
				printf("\nthe queue is full !!!\n");
			}

			else if(i==3)
			{
				printf("\nthe queue is empty !!!\n");
			}
		}

		else if(x==1)
		{
			if(FIFO_stat(&buffer,32)!= FIFO_EMPTY)
			{
				FIFO_print(&buffer,32);
			}
			else printf("\nthe queue is empty !!!\n");
		}

		else if(x==2)
		{
			if(FIFO_stat(&buffer,32)!= FIFO_FULL)
			{
				int i;
				printf("\nenter the element:");
				fflush(stdin); fflush(stdout);
				scanf("%d",&i);
				FIFO_enqueue(&buffer,i,32);
			}
			else printf("\nthe queue is full !!!\n");
		}

		else if(x==3)
		{
			if(FIFO_stat(&buffer,32)!= FIFO_EMPTY)
			{
				int i;
				FIFO_dequeue(&buffer,&i,32);
				printf("\nthe element is: %d\n",i);
			}
			else printf("\nthe queue is empty !!!\n");
		}

		else if(x==4)
		{
			buffer.count = 0;
			buffer.head = buffer.base;
			buffer.tail = buffer.base;
			printf("\nthe queue is erased !!!\n");
		}

		else if(x==5)
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
