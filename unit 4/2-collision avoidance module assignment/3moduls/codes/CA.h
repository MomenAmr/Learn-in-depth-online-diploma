/*
 * CA.h
 *
 *  Created on: Jun 20, 2022
 *      Author: momen
 */

#ifndef CA_H_
#define CA_H_

#include"state.h"

void(*CA_state)();

STATE_define(CA_waiting);
STATE_define(CA_driving);

#endif /* CA_H_ */
