/*
 * state.h
 *
 *  Created on: Jun 25, 2022
 *      Author: momen
 */

#ifndef STATE_H_
#define STATE_H_

#include"stdio.h"
#include"stdlib.h"
#include"driver.h"

enum
{
	PS_init, PS_busy, PS_idle
}
state_Psensor_id;


enum
{
	HPD_aquiring, HPD_calculating
}
state_HPdetector_id;

enum
{
	AD_stop, AD_start, AD_waiting
}
state_Alarm_driver_id;

enum
{
	AA_init, AA_ON, AA_OFF, AA_waiting
}
state_Alarm_actuator_id;


#define STATE_define(state_function) void ST_##state_function()
#define STATE(state_function) ST_##state_function

void HPD_aquire_value (int p);
void High_pressure_detected ();
void AD_set_alarm (char c);

#endif /* STATE_H_ */
