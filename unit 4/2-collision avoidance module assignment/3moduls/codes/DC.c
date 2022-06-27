/*
 * DC.c
 *
 *  Created on: Jun 21, 2022
 *      Author: momen
 */

#include"DC.h"

unsigned int DC_Speed;

void DC_set_speed (int s)
{
	DC_Speed = s;
	printf("CA control speed: %d ----->----->-----> motor driver\n",DC_Speed);
	DC_state = STATE(DC_busy);
}

STATE_define(DC_init)
{
	printf("motor driver enabled and initialized !\n");
}

STATE_define(DC_idle)
{
	state_DC_id = DC_idle;
	printf("motor driver state: idle    speed = %d\n",DC_Speed);
}

STATE_define(DC_busy)
{
	state_DC_id = DC_busy;
	printf("motor driver state: busy    speed = %d\n",DC_Speed);
	DC_state = STATE(DC_idle);
}

