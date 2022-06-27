/*
 * Alarm_driver.h
 *
 *  Created on: Jun 25, 2022
 *      Author: momen
 */

#ifndef ALARM_DRIVER_H_
#define ALARM_DRIVER_H_

void (*Alarm_driver_STATE)();

STATE_define(AD_stop);
STATE_define(AD_start);
STATE_define(AD_waiting);

#endif /* ALARM_DRIVER_H_ */
