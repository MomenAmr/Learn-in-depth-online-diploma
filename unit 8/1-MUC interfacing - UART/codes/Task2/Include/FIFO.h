/*
 * FIFO.h
 *
 * Created: 7/20/2022 11:05:39 AM
 *  Author: momen
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
	
}FIFO_Buffer;

char FIFO_enqueue(FIFO_Buffer* buffer, char item);
char FIFO_dequeue(FIFO_Buffer* buffer, char* item);

#endif /* FIFO_H_ */