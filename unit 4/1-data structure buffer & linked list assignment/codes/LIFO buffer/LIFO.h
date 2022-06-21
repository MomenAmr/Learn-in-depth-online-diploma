/*
 * LIFO.h
 *
 *  Created on: Jun 18, 2022
 *      Author: m'omen amr
 */

#ifndef LIFO_H_
#define LIFO_H_

typedef struct
{
	unsigned int length;
	unsigned int count;
	unsigned char* base;
	unsigned char* top;
}LIFO_Buffer_8;

typedef struct
{
	unsigned int length;
	unsigned int count;
	unsigned short* base;
	unsigned short* top;
}LIFO_Buffer_16;

typedef struct
{
	unsigned int length;
	unsigned int count;
	unsigned int* base;
	unsigned int* top;
}LIFO_Buffer_32;

typedef struct
{
	unsigned int length;
	unsigned int count;
	unsigned long long* base;
	unsigned long long* top;
}LIFO_Buffer_64;

typedef enum
{
	LIFO_NULL, LIFO_OK, LIFO_FULL, LIFO_EMPTY
}buffer_status;


buffer_status LIFO_stat(void* buffer, int type);
buffer_status LIFO_add(void* buffer, int item, int type);
buffer_status LIFO_get(void* buffer, int* item, int type);


#endif /* LIFO_H_ */
