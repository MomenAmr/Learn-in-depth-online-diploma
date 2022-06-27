/*
 * main.c
 *
 *  Created on: Jun 25, 2022
 *      Author: momen
 */



#include"state.h"
#include"driver.h"
#include"Pressure_sensor.h"
#include"High_pressure_detector.h"
#include"Alarm_driver.h"
#include"Alarm_actuator.h"

void setup()
{
	//this function will be executed only once at the start which initialize all the modules needed for the program
	GPIO_INITIALIZATION ();
	STATE(PS_init) ();
	STATE(AA_init) ();
	//no need to initialize all the function pointers as they will be initialized when the preceding functions are called
	Alarm_driver_STATE = STATE(AD_stop);
}

void Pressure_controller()
{
	setup();
	while(1)
	{
		//instead of calling a function inside another we can use pointers to functions to work in periodic blocking manner
		Psensor_STATE();
		HPdetector_STATE();
		Alarm_driver_STATE();
		Alarm_actuator_STATE();
	}
}
