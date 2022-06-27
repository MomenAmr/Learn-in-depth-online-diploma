/*
 * HPD.c
 *
 *  Created on: Jun 25, 2022
 *      Author: momen
 */

#include"state.h"
#include"High_pressure_detector.h"

int Psensor_val;
int HPD_threshold = 20;

void HPD_aquire_value (int p)
{
	//this function acts as a channel between the sensor and the detector and sets the detector to enter the
	//calculating state next time it's called to check the reading against the threshold
	state_HPdetector_id = HPD_aquiring;
	Psensor_val = p;
	HPdetector_STATE = STATE(HPD_calculating);
}

STATE_define(HPD_calculating)
{
	//this is a guard to not overwhelm the alarm driver when sending every time the function is called as it can be called
	//for two times already when the alarm driver tries to enter the waiting state leading it to go into start state again
	//so the function is called only once when the sensor sends a higher value than the threshold and if the detector still
	//reads the same reading because the sensor is blocked due to alarm being activated then it doesn't call the function
	if((state_HPdetector_id == HPD_aquiring)&&(Psensor_val > HPD_threshold)) High_pressure_detected ();
	state_HPdetector_id = HPD_calculating;
}
