/*
 * main.c
 *
 *  Created on: Jun 18, 2022
 *      Author: m'omen amr
 */

#include "stdio.h"
#include "LIFO.h"

unsigned int arr[5];

void main()
{

	LIFO_Buffer_32 buffer = {5,0,arr,arr};

	while(1)
	{
		int x;
		printf("\nwhat operation do you wish to execute on stack?\n	0-check stack status\n	1-display stack\n	2-add element to stack\n	3-get element from stack\n	4-erase stack\n	5-terminate program\nyour choise is:");
		fflush(stdin); fflush(stdout);
		scanf("%d",&x);

		if(x==0)
		{
			int i = LIFO_stat(&buffer,32);

			if (i==0)
			{
				printf("\nthe stack could not be successfully established !!!\n");
			}

			else if(i==1)
			{
				printf("\nthe stack successfully established !!!\n");
			}

			else if(i==2)
			{
				printf("\nthe stack is full !!!\n");
			}

			else if(i==3)
			{
				printf("\nthe stack is empty !!!\n");
			}
		}

		else if(x==1)
		{
			if(LIFO_stat(&buffer,32)!= LIFO_EMPTY)
			{
				int i;
				unsigned int* p = buffer.base;
				printf("\n");
				for(i=0;i<buffer.count;i++)
				{
					printf("%d ",*p++);
				}
				printf("\n");
			}
			else printf("\nthe stack is empty !!!\n");
		}

		else if(x==2)
		{
			if(LIFO_stat(&buffer,32)!= LIFO_FULL)
			{
				int i;
				printf("\nenter the element:");
				fflush(stdin); fflush(stdout);
				scanf("%d",&i);
				LIFO_add(&buffer,i,32);
			}
			else printf("\nthe stack is full !!!\n");
		}

		else if(x==3)
		{
			if(LIFO_stat(&buffer,32)!= LIFO_EMPTY)
			{
				int i;
				LIFO_get(&buffer,&i,32);
				printf("\nthe element is: %d\n",i);
			}
			else printf("\nthe stack is empty !!!\n");
		}

		else if(x==4)
		{
			buffer.count = 0;
			buffer.top = buffer.base;
			printf("\nthe stack is erased !!!\n");
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
