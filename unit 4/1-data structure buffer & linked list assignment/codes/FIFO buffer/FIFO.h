/*
 * FIFO.h
 *
 *  Created on: Jun 19, 2022
 *      Author: momen
 */

#ifndef FIFO_H_
#define FIFO_H_

typedef struct
{
	unsigned int length;
	unsigned int count;
	unsigned char* base;
	unsigned char* head;
	unsigned char* tail;
}FIFO_Buffer_8;

typedef struct
{
	unsigned int length;
	unsigned int count;
	unsigned short* base;
	unsigned short* head;
	unsigned short* tail;
}FIFO_Buffer_16;

typedef struct
{
	unsigned int length;
	unsigned int count;
	unsigned int* base;
	unsigned int* head;
	unsigned int* tail;
}FIFO_Buffer_32;

typedef struct
{
	unsigned int length;
	unsigned int count;
	unsigned long long* base;
	unsigned long long* head;
	unsigned long long* tail;
}FIFO_Buffer_64;

typedef enum
{
	FIFO_NULL, FIFO_OK, FIFO_FULL, FIFO_EMPTY
}buffer_status;


buffer_status FIFO_stat(void* buffer, int type);
buffer_status FIFO_print(void* buffer, int type);
buffer_status FIFO_enqueue(void* buffer, int item, int type);
buffer_status FIFO_dequeue(void* buffer, int* item, int type);


#endif /* FIFO_H_ */
