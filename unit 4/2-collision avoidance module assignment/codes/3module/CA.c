/*
 * CA.c
 *
 *  Created on: Jun 20, 2022
 *      Author: momen
 */

#include"CA.h"

unsigned int CA_Speed=0;
unsigned int CA_Distance=0;
unsigned int CA_Threshold=50;

void US_get_distance (int d)
{
	CA_Distance = d;
	printf("ultra_sonic distance: %d ----->----->-----> CA control\n",CA_Distance);
	(CA_Distance<=CA_Threshold)? (CA_state = STATE(CA_waiting)) : (CA_state = STATE(CA_driving));
}

STATE_define(CA_waiting)
{
	state_CA_id = CA_waiting;
	CA_Speed = 0;

	printf("CA control state: waiting   distance = %d   speed = %d\n\n",CA_Distance,CA_Speed);
	DC_set_speed (CA_Speed);

}

STATE_define(CA_driving)
{
	state_CA_id = CA_driving;
	CA_Speed = 30;

	printf("CA control state: driving   distance = %d   speed = %d\n\n",CA_Distance,CA_Speed);
	DC_set_speed (CA_Speed);

}

