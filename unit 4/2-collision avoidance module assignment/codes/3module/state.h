/*
 * state.h
 *
 *  Created on: Jun 20, 2022
 *      Author: momen
 */


#ifndef STATE_H_
#define STATE_H_

#include"stdio.h"
#include"stdlib.h"

enum
{
	CA_waiting, CA_driving
}
state_CA_id;


enum
{
	US_busy
}
state_US_id;

enum
{
	DC_idle, DC_busy
}
state_DC_id;


#define STATE_define(state_function) void ST_##state_function()
#define STATE(state_function) ST_##state_function

void US_get_distance (int d);
void DC_set_speed (int s);

#endif /* STATE_H_ */
