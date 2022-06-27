/*
 * CA.c
 *
 *  Created on: Jun 20, 2022
 *      Author: momen
 */

#include"state.h"
#include"CA.h"

int CA_Speed=0;
int CA_Distance=0;
int CA_Threshold=50;

int Get_distance_random(int l , int r)
{
	return 	( (rand()% (r-l+1)) + l);
}


STATE_define(waiting)
{
	state_id = waiting;
	CA_Speed=0;
	CA_Distance = Get_distance_random(45 , 55);

	(CA_Distance<=CA_Threshold)? (state = STATE(waiting)) : (state = STATE(driving));
	printf("waiting state:\tspeed = %d\tdistance = %d\n",CA_Speed,CA_Distance);
}

STATE_define(driving)
{
	state_id = driving;
	CA_Speed=30;
	CA_Distance = Get_distance_random(45 , 55);

	(CA_Distance<=CA_Threshold)? (state = STATE(waiting)) : (state = STATE(driving));
	printf("driving state:\tspeed = %d\tdistance = %d\n",CA_Speed,CA_Distance);

}

