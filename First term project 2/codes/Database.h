/*
 * Database.h
 *
 *  Created on: Jun 26, 2022
 *      Author: momen
 */

#ifndef DATABASE_H_
#define DATABASE_H_

struct sinfo
{
	char  fname[50];
	char  lname[50];
	int   roll;
	float GPA;
	int   cid[10];
}st[55];

void add_student_manually();
void add_student_file();
void find_rl();
void find_fn();
void find_c();
void tot_s();
void del_s();
void up_s();
void show_s();

#endif /* DATABASE_H_ */
