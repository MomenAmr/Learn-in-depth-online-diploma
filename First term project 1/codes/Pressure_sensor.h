/*
 * Pressure_sensor.h
 *
 *  Created on: Jun 25, 2022
 *      Author: momen
 */

#ifndef PRESSURE_SENSOR_H_
#define PRESSURE_SENSOR_H_

void (*Psensor_STATE)();

STATE_define(PS_init);
STATE_define(PS_busy);
STATE_define(PS_idle);

#endif /* PRESSURE_SENSOR_H_ */
