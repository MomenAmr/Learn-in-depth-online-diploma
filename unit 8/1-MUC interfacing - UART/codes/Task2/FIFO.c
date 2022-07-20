/*
 * FIFO.c
 *
 * Created: 7/20/2022 11:06:43 AM
 *  Author: momen
 */ 

#include "Include/FIFO.h"

char FIFO_enqueue(FIFO_Buffer* buffer, char item)
{
	if(buffer->count == buffer->length) return 0;
	else
	{
		*buffer->head = item;
		buffer->count++;

		if ((unsigned int)buffer->head == ((unsigned int)buffer->base + (buffer->length-1)))
		buffer->head = buffer->base;
		else buffer->head++;

		return 1;
	}
}

char FIFO_dequeue(FIFO_Buffer* buffer, char* item)
{
	if(buffer->count == 0) return 0;
	else
	{
		*item = *buffer->tail;
		buffer->count--;

		if ((unsigned int)buffer->tail == ((unsigned int)buffer->base + (buffer->length-1)))
		buffer->tail = buffer->base;
		else buffer->tail++;

		return 1;
	}
}