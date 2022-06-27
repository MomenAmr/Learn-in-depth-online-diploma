/*
 * US.h
 *
 *  Created on: Jun 21, 2022
 *      Author: momen
 */

#ifndef US_H_
#define US_H_

#include"state.h"

void(*US_state)();

int Get_distance_random(int, int);
STATE_define(US_init);
STATE_define(US_busy);

#endif /* US_H_ */
