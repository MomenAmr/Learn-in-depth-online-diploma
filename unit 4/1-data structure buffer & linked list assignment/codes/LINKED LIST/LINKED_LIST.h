/*
 * LINKED_LIST.h
 *
 *  Created on: Jun 19, 2022
 *      Author: momen
 */

#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

#include "stdio.h"
#include "stdlib.h"

struct Sdata
{
	int ID;
	float height;
	char name[40];
};

struct Sstudent
{
	struct Sdata student;
	struct Sstudent* next_student;
};

void student_add(struct Sstudent** list);
void student_fill_data(struct Sstudent* student);
void student_delete(struct Sstudent** list,int ID);
void student_find(struct Sstudent** list, int index);
void list_view(struct Sstudent** list);
void list_delete(struct Sstudent** list);
void list_reverse(struct Sstudent** list);
void list_middle(struct Sstudent** list);
int list_len(struct Sstudent** list);
#endif /* LINKED_LIST_H_ */
