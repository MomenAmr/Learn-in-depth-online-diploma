/*
 * Alarm_actuator.c
 *
 *  Created on: Jun 25, 2022
 *      Author: momen
 */


#include"state.h"
#include"Alarm_actuator.h"

void AD_set_alarm (char c)
{
	//this works as a channel between the driver and the actuator so whenever a signal is sent, the alarm goes from
	//waiting state into closing or opening the alarm
	if(c=='o') Alarm_actuator_STATE = STATE(AA_ON);
	else if(c=='f') Alarm_actuator_STATE = STATE(AA_OFF);
}

STATE_define(AA_init)
{
	state_Alarm_actuator_id = AA_init;
	//initializing the alarm module
	Set_Alarm_actuator(1);
	Delay(10000);
	Alarm_actuator_STATE = STATE(AA_waiting);
}

STATE_define(AA_waiting)
{
	//do nothing
	state_Alarm_actuator_id = AA_waiting;
}

STATE_define(AA_ON)
{
	state_Alarm_actuator_id = AA_ON;
	//drive the gpio pin set as output to low driving the external load to high
	Set_Alarm_actuator(0);
	Alarm_actuator_STATE = STATE(AA_waiting);
}

STATE_define(AA_OFF)
{
	state_Alarm_actuator_id = AA_OFF;
	//drive the gpio pin set as output to high driving the external load to low
	Set_Alarm_actuator(1);
	Alarm_actuator_STATE = STATE(AA_waiting);
}
