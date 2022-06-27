/*
 * US.c
 *
 *  Created on: Jun 21, 2022
 *      Author: momen
 */

#include"US.h"

unsigned int US_distance;

int Get_distance_random(int l , int r)
{
	return 	( (rand()% (r-l+1)) + l);
}

STATE_define(US_init)
{
	printf("ultra_sonic sensor enabled and initialized !\n");
}

STATE_define(US_busy)
{
	state_US_id = US_busy;
	US_distance = Get_distance_random(45,55);

	printf("\n\n\nultra_sonic state: busy     Distance = %d\n\n",US_distance);
	US_get_distance(US_distance);
	US_state= STATE(US_busy);
}
