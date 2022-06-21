/*
 * CA.h
 *
 *  Created on: Jun 20, 2022
 *      Author: momen
 */


#ifndef CA_H_
#define CA_H_

#include"state.h"
#include"stdio.h"
#include"stdlib.h"

void (*state)();

STATE_define(waiting);
STATE_define(driving);
int Get_distance_random(int l , int r);

#endif /* CA_H_ */
