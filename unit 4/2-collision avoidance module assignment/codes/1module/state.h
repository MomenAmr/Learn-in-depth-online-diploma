/*
 * state.h
 *
 *  Created on: Jun 20, 2022
 *      Author: momen
 */


#ifndef STATE_H_
#define STATE_H_

enum
{
	waiting, driving
}
state_id;

#define STATE_define(state_function) void ST_##state_function()
#define STATE(state_function) ST_##state_function


#endif /* STATE_H_ */
