/*
 * Pressure_sensor.c
 *
 *  Created on: Jun 25, 2022
 *      Author: momen
 */

#include"state.h"
#include"Pressure_sensor.h"

int Pval;

STATE_define(PS_init)
{
	state_Psensor_id = PS_init;
	// initialize parameters for pressure sensor
	Psensor_STATE = STATE(PS_busy);
}

STATE_define(PS_busy)
{
	state_Psensor_id = PS_busy;
	//reading the gpio port set as 8bit input
	Pval = getPressureVal();

	//although it's lacking, sending the sensor reading through a channel to the detector block, which is why we use
	//global variable in the first place but this is for demonstrating modularity only
	HPD_aquire_value(Pval);
	//after sending the reading to the detector we set the parameters for it to function properly when it runs
	//then return here so we don't call the detector function here leading to stack consumption
	Psensor_STATE = STATE(PS_idle);
}

STATE_define(PS_idle)
{
	//to use delay here is not effective for this to function as a guard, we must use hardware timer
	//and since we can't yet, we can implement the guard differently by checking if an alarm is OFF
	state_Psensor_id = PS_idle;
	if(state_Alarm_actuator_id == AA_OFF) Psensor_STATE = STATE(PS_busy);

}
