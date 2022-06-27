/*
 * DC.h
 *
 *  Created on: Jun 21, 2022
 *      Author: momen
 */

#ifndef DC_H_
#define DC_H_

#include"state.h"

void(*DC_state)();

STATE_define(DC_init);
STATE_define(DC_idle);
STATE_define(DC_busy);

#endif /* DC_H_ */
