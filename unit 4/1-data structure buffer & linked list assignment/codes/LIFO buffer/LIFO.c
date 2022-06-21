/*
 * LIFO.c
 *
 *  Created on: Jun 18, 2022
 *      Author: m'omen amr
 */

#include "LIFO.h"

buffer_status LIFO_stat(void* buffer_all, int type)
{

	if(type==8)
	{
		LIFO_Buffer_8* buffer = buffer_all;
		if(!buffer || !buffer->base || !buffer->top ) return LIFO_NULL;
		if(buffer->count == buffer->length) return LIFO_FULL;
		if(buffer->count == 0) return LIFO_EMPTY;
		else return LIFO_OK;
	}

	else if(type==16)
	{
		LIFO_Buffer_16* buffer = buffer_all;
		if(!buffer || !buffer->base || !buffer->top ) return LIFO_NULL;
		if(buffer->count == buffer->length) return LIFO_FULL;
		if(buffer->count == 0) return LIFO_EMPTY;
		else return LIFO_OK;
	}

	else if(type==32)
	{
		LIFO_Buffer_32* buffer = buffer_all;
		if(!buffer || !buffer->base || !buffer->top ) return LIFO_NULL;
		if(buffer->count == buffer->length) return LIFO_FULL;
		if(buffer->count == 0) return LIFO_EMPTY;
		else return LIFO_OK;
	}

	else
	{
		LIFO_Buffer_64* buffer = buffer_all;
		if(!buffer || !buffer->base || !buffer->top ) return LIFO_NULL;
		if(buffer->count == buffer->length) return LIFO_FULL;
		if(buffer->count == 0) return LIFO_EMPTY;
		else return LIFO_OK;
	}
}

buffer_status LIFO_add(void* buffer_all, int item, int type)
{
	if(type==8)
	{
		LIFO_Buffer_8* buffer = buffer_all;
		if(LIFO_stat(buffer,8) == LIFO_NULL) return LIFO_NULL;
		if(LIFO_stat(buffer,8) != LIFO_FULL)
		{
			*buffer->top = item;
			buffer->top++;
			buffer->count++;
			return LIFO_OK;
		}
		else return LIFO_FULL;
	}

	else if(type==16)
	{
		LIFO_Buffer_16* buffer = buffer_all;
		if(LIFO_stat(buffer,16) == LIFO_NULL) return LIFO_NULL;
		if(LIFO_stat(buffer,16) != LIFO_FULL)
		{
			*buffer->top = item;
			buffer->top++;
			buffer->count++;
			return LIFO_OK;
		}
		else return LIFO_FULL;
	}

	else if(type==32)
	{
		LIFO_Buffer_32* buffer = buffer_all;
		if(LIFO_stat(buffer,32) == LIFO_NULL) return LIFO_NULL;
		if(LIFO_stat(buffer,32) != LIFO_FULL)
		{
			*buffer->top = item;
			buffer->top++;
			buffer->count++;
			return LIFO_OK;
		}
		else return LIFO_FULL;
	}

	else
	{
		LIFO_Buffer_64* buffer = buffer_all;
		if(LIFO_stat(buffer,64) == LIFO_NULL) return LIFO_NULL;
		if(LIFO_stat(buffer,64) != LIFO_FULL)
		{
			*buffer->top = item;
			buffer->top++;
			buffer->count++;
			return LIFO_OK;
		}
		else return LIFO_FULL;
	}
}

buffer_status LIFO_get(void* buffer_all, int* item, int type)
{
	if(type==8)
	{
		LIFO_Buffer_8* buffer = buffer_all;
		if(LIFO_stat(buffer,8) == LIFO_NULL) return LIFO_NULL;
		if(LIFO_stat(buffer,8) != LIFO_EMPTY)
		{
			buffer->top--;
			*item = *buffer->top;
			buffer->count--;
			return LIFO_OK;
		}
		else return LIFO_EMPTY;
	}

	else if(type==16)
	{
		LIFO_Buffer_16* buffer = buffer_all;
		if(LIFO_stat(buffer,16) == LIFO_NULL) return LIFO_NULL;
		if(LIFO_stat(buffer,16) != LIFO_EMPTY)
		{
			buffer->top--;
			*item = *buffer->top;
			buffer->count--;
			return LIFO_OK;
		}
		else return LIFO_EMPTY;
	}

	else if(type==32)
	{
		LIFO_Buffer_32* buffer = buffer_all;
		if(LIFO_stat(buffer,32) == LIFO_NULL) return LIFO_NULL;
		if(LIFO_stat(buffer,32) != LIFO_EMPTY)
		{
			buffer->top--;
			*item = *buffer->top;
			buffer->count--;
			return LIFO_OK;
		}
		else return LIFO_EMPTY;
	}

	else
	{
		LIFO_Buffer_64* buffer = buffer_all;
		if(LIFO_stat(buffer,64) == LIFO_NULL) return LIFO_NULL;
		if(LIFO_stat(buffer,64) != LIFO_EMPTY)
		{
			buffer->top--;
			*item = *buffer->top;
			buffer->count--;
			return LIFO_OK;
		}
		else return LIFO_EMPTY;
	}
}
