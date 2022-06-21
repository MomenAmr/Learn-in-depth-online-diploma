/*
 * FIFO.c
 *
 *  Created on: Jun 19, 2022
 *      Author: momen
 */
#include "FIFO.h"
#include "stdio.h"

buffer_status FIFO_stat(void* buffer_all, int type)
{

	if(type==8)
	{
		FIFO_Buffer_8* buffer = buffer_all;
		if(!buffer || !buffer->base || !buffer->head || !buffer->tail ) return FIFO_NULL;
		if(buffer->count == buffer->length) return FIFO_FULL;
		if(buffer->count == 0) return FIFO_EMPTY;
		else return FIFO_OK;
	}

	else if(type==16)
	{
		FIFO_Buffer_16* buffer = buffer_all;
		if(!buffer || !buffer->base || !buffer->head || !buffer->tail ) return FIFO_NULL;
		if(buffer->count == buffer->length) return FIFO_FULL;
		if(buffer->count == 0) return FIFO_EMPTY;
		else return FIFO_OK;
	}

	else if(type==32)
	{
		FIFO_Buffer_32* buffer = buffer_all;
		if(!buffer || !buffer->base || !buffer->head || !buffer->tail ) return FIFO_NULL;
		if(buffer->count == buffer->length) return FIFO_FULL;
		if(buffer->count == 0) return FIFO_EMPTY;
		else return FIFO_OK;
	}

	else
	{
		FIFO_Buffer_64* buffer = buffer_all;
		if(!buffer || !buffer->base || !buffer->head || !buffer->tail ) return FIFO_NULL;
		if(buffer->count == buffer->length) return FIFO_FULL;
		if(buffer->count == 0) return FIFO_EMPTY;
		else return FIFO_OK;
	}
}

buffer_status FIFO_print(void* buffer_all, int type)
{
	if(type==8)
	{
		FIFO_Buffer_8* buffer = buffer_all;

		if(FIFO_stat(buffer,8) == FIFO_NULL)
			return FIFO_NULL;

		if(FIFO_stat(buffer,8) != FIFO_EMPTY)
		{
			printf("\n");

			if(buffer->head > buffer->tail)
			{
				int i;
				unsigned short * p = buffer->tail;

				for(i=0;i<buffer->count;i++)
				{
					printf("  %d",*p++);
				}
				printf("\n");
				return FIFO_OK;
			}

			else
			{
				int i;
				unsigned char * p = buffer->tail;

				for(i=0;((unsigned int)p <= ((unsigned int)buffer->base + (buffer->length-1)));i++)
				{
					printf("  %d",*p++);
				}

				if (i < buffer->count)
				{
					p = buffer->base;
					for(i=0;p<buffer->head;i++)
					{
						printf("  %d",*p++);
					}
				}
				printf("\n");
				return FIFO_OK;
			}
		}
		else return FIFO_EMPTY;

	}

	else if(type==16)
	{
		FIFO_Buffer_16* buffer = buffer_all;

		if(FIFO_stat(buffer,16) == FIFO_NULL)
			return FIFO_NULL;

		if(FIFO_stat(buffer,16) != FIFO_EMPTY)
		{
			printf("\n");
			if(buffer->head > buffer->tail)
			{
				int i;
				unsigned short * p = buffer->tail;

				for(i=0;i<buffer->count;i++)
				{
					printf("  %d",*p++);
				}
				printf("\n");
				return FIFO_OK;
			}

			else
			{
				int i;
				unsigned short * p = buffer->tail;

				for(i=0;((unsigned int)p <= ((unsigned int)buffer->base + 2 * (buffer->length-1)));i++)
				{
					printf("  %d",*p++);
				}

				if (i < buffer->count)
				{
					p = buffer->base;
					for(i=0;p<buffer->head;i++)
					{
						printf("  %d",*p++);
					}
				}
				printf("\n");
				return FIFO_OK;
			}
		}
		else return FIFO_EMPTY;

	}

	else if(type==32)
	{
		FIFO_Buffer_32* buffer = buffer_all;

		if(FIFO_stat(buffer,32) == FIFO_NULL)
			return FIFO_NULL;

		if(FIFO_stat(buffer,32) != FIFO_EMPTY)
		{
			printf("\n");
			if(buffer->head > buffer->tail)
			{
				int i;
				unsigned int * p = buffer->tail;

				for(i=0;i<buffer->count;i++)
				{
					printf("  %d",*p++);
				}
				printf("\n");
				return FIFO_OK;
			}

			else
			{
				int i;
				unsigned int * p = buffer->tail;

				for(i=0;((unsigned int)p <= ((unsigned int)buffer->base + 4 * (buffer->length-1)));i++)
				{
					printf("  %d",*p++);
				}

				if (i < buffer->count)
				{
					p = buffer->base;
					for(i=0;p<buffer->head;i++)
					{
						printf("  %d",*p++);
					}
				}
				printf("\n");
				return FIFO_OK;
			}
		}
		else return FIFO_EMPTY;

	}

	else
	{
		FIFO_Buffer_64* buffer = buffer_all;

		if(FIFO_stat(buffer,64) == FIFO_NULL)
			return FIFO_NULL;

		if(FIFO_stat(buffer,64) != FIFO_EMPTY)
		{
			printf("\n");
			if(buffer->head > buffer->tail)
			{
				int i;
				unsigned long long * p = buffer->tail;

				for(i=0;i<buffer->count;i++)
				{
					printf("  %d",*p++);
				}
				printf("\n");
				return FIFO_OK;
			}

			else
			{
				int i;
				unsigned long long * p = buffer->tail;

				for(i=0;((unsigned int)p <= ((unsigned int)buffer->base + 8 * (buffer->length-1)));i++)
				{
					printf("  %d",*p++);
				}

				if (i < buffer->count)
				{
					p = buffer->base;
					for(i=0;p<buffer->head;i++)
					{
						printf("  %d",*p++);
					}
				}
				printf("\n");
				return FIFO_OK;
			}
		}
		else return FIFO_EMPTY;

	}
}

buffer_status FIFO_enqueue(void* buffer_all, int item, int type)
{
	if(type==8)
	{
		FIFO_Buffer_8* buffer = buffer_all;
		if(FIFO_stat(buffer,8) == FIFO_NULL) return FIFO_NULL;
		if(FIFO_stat(buffer,8) != FIFO_FULL)
		{
			*buffer->head = item;
			buffer->count++;

			if ((unsigned int)buffer->head == ((unsigned int)buffer->base + (buffer->length-1)))
				buffer->head = buffer->base;
			else buffer->head++;

			return FIFO_OK;
		}
		else return FIFO_FULL;
	}

	else if(type==16)
	{
		FIFO_Buffer_16* buffer = buffer_all;
		if(FIFO_stat(buffer,16) == FIFO_NULL) return FIFO_NULL;
		if(FIFO_stat(buffer,16) != FIFO_FULL)
		{
			*buffer->head = item;
			buffer->count++;

			if ((unsigned int)buffer->head == ((unsigned int)buffer->base + 2*(buffer->length-1)))
				buffer->head = buffer->base;
			else buffer->head++;

			return FIFO_OK;
		}
		else return FIFO_FULL;
	}

	else if(type==32)
	{
		FIFO_Buffer_32* buffer = buffer_all;
		if(FIFO_stat(buffer,32) == FIFO_NULL) return FIFO_NULL;
		if(FIFO_stat(buffer,32) != FIFO_FULL)
		{
			*buffer->head = item;
			buffer->count++;

			if ((unsigned int)buffer->head == ((unsigned int)buffer->base + 4*(buffer->length-1)))
				buffer->head = buffer->base;
			else buffer->head++;

			return FIFO_OK;
		}
		else return FIFO_FULL;
	}

	else
	{
		FIFO_Buffer_64* buffer = buffer_all;
		if(FIFO_stat(buffer,64) == FIFO_NULL) return FIFO_NULL;
		if(FIFO_stat(buffer,64) != FIFO_FULL)
		{
			*buffer->head = item;
			buffer->count++;

			if ((unsigned int)buffer->head == ((unsigned int)buffer->base + 8*(buffer->length-1)))
				buffer->head = buffer->base;
			else buffer->head++;

			return FIFO_OK;
		}
		else return FIFO_FULL;
	}
}

buffer_status FIFO_dequeue(void* buffer_all, int* item, int type)
{
	if(type==8)
	{
		FIFO_Buffer_8* buffer = buffer_all;
		if(FIFO_stat(buffer,8) == FIFO_NULL) return FIFO_NULL;
		if(FIFO_stat(buffer,8) != FIFO_EMPTY)
		{
			*item = *buffer->tail;
			buffer->count--;

			if ((unsigned int)buffer->tail == ((unsigned int)buffer->base + (buffer->length-1)))
				buffer->tail = buffer->base;
			else buffer->tail++;

			return FIFO_OK;
		}
		else return FIFO_EMPTY;
	}

	else if(type==16)
	{
		FIFO_Buffer_16* buffer = buffer_all;
		if(FIFO_stat(buffer,16) == FIFO_NULL) return FIFO_NULL;
		if(FIFO_stat(buffer,16) != FIFO_EMPTY)
		{
			*item = *buffer->tail;
			buffer->count--;

			if ((unsigned int)buffer->tail == ((unsigned int)buffer->base + 2*(buffer->length-1)))
				buffer->tail = buffer->base;
			else buffer->tail++;

			return FIFO_OK;
		}
		else return FIFO_EMPTY;
	}

	else if(type==32)
	{
		FIFO_Buffer_32* buffer = buffer_all;
		if(FIFO_stat(buffer,32) == FIFO_NULL) return FIFO_NULL;
		if(FIFO_stat(buffer,32) != FIFO_EMPTY)
		{
			*item = *buffer->tail;
			buffer->count--;

			if ((unsigned int)buffer->tail == ((unsigned int)buffer->base + 4*(buffer->length-1)))
				buffer->tail = buffer->base;
			else buffer->tail++;

			return FIFO_OK;
		}
		else return FIFO_EMPTY;
	}

	else
	{
		FIFO_Buffer_64* buffer = buffer_all;
		if(FIFO_stat(buffer,64) == FIFO_NULL) return FIFO_NULL;
		if(FIFO_stat(buffer,64) != FIFO_EMPTY)
		{
			*item = *buffer->tail;
			buffer->count--;

			if ((unsigned int)buffer->tail == ((unsigned int)buffer->base + 8*(buffer->length-1)))
				buffer->tail = buffer->base;
			else buffer->tail++;

			return FIFO_OK;
		}
		else return FIFO_EMPTY;
	}
}
