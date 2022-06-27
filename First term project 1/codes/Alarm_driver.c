/*
 * Alarm_driver.c
 *
 *  Created on: Jun 25, 2022
 *      Author: momen
 */


#include"state.h"
#include"Alarm_driver.h"


void High_pressure_detected ()
{
	//this works as guard because the alarm driver has a delay before closing the alarm so if the function gets called
	//when it is in stop state when it starts the alarm and goes to the waiting state which will be called the next time
	//it's not the way to go and has too many flows and is not recommended to implement but as instructed to work in an
	//emulated synchronous blocking process without calling functions inside functions to guard the stack this is it

	if(state_Alarm_driver_id == AD_stop) Alarm_driver_STATE = STATE(AD_start);
}

STATE_define(AD_stop)
{
	state_Alarm_driver_id = AD_stop;
	//sending a signal to the alarm actuator to turn off
	AD_set_alarm ('f');
}

STATE_define(AD_start)
{
	state_Alarm_driver_id = AD_start;
	//sending a signal to the alarm actuator to turn on
	AD_set_alarm ('o');
	Alarm_driver_STATE = STATE(AD_waiting);
}

STATE_define(AD_waiting)
{
	state_Alarm_driver_id = AD_waiting;
	//waiting for supposed 60 seconds before turning the alarm off, it's more like 6 seconds not 60 but it works as intended
	Delay(3600000);
	Alarm_driver_STATE = STATE(AD_stop);
}
