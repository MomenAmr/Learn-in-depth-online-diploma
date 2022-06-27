/*
 * FIFO.h
 *
 *  Created on: Jun 19, 2022
 *      Author: momen
 */

#ifndef FIFO_H_
#define FIFO_H_

#include"Database.h"

typedef struct
{
	unsigned int length;
	unsigned int count;
	struct sinfo* base;
	struct sinfo* head;
	struct sinfo* tail;
}FIFO_Buffer;

typedef enum
{
	FIFO_NULL, FIFO_OK, FIFO_FULL, FIFO_EMPTY, FIFO_DUPLICATE_ID, FIFO_NO_ID
}buffer_status;

buffer_status FIFO_find(FIFO_Buffer* buffer, int roll, char*name, int cid);
buffer_status FIFO_update(FIFO_Buffer* buffer, int roll, int choice);
buffer_status FIFO_init(FIFO_Buffer* buffer, struct sinfo* array, int length);
buffer_status FIFO_check_duplicate(FIFO_Buffer* buffer, int roll);
buffer_status FIFO_stat(FIFO_Buffer* buffer);
buffer_status FIFO_enqueue(FIFO_Buffer* buffer, struct sinfo* temp);
buffer_status FIFO_print(FIFO_Buffer* buffer);
buffer_status FIFO_delete(FIFO_Buffer* buffer, int roll);


#endif /* FIFO_H_ */
