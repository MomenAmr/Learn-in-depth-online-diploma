/*
 * Alarm_actuator.h
 *
 *  Created on: Jun 25, 2022
 *      Author: momen
 */

#ifndef ALARM_ACTUATOR_H_
#define ALARM_ACTUATOR_H_

void (*Alarm_actuator_STATE)();

STATE_define(AA_init);
STATE_define(AA_ON);
STATE_define(AA_OFF);
STATE_define(AA_waiting);

#endif /* ALARM_ACTUATOR_H_ */
