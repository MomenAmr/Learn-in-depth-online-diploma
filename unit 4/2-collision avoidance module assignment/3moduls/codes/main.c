/*
 * main.c
 *
 *  Created on: Jun 21, 2022
 *      Author: momen
 */

#include "CA.h"
#include "US.h"
#include "DC.h"

void setup()
{
	STATE(US_init)();
	STATE(DC_init)();

	US_state= STATE(US_busy);
	CA_state= STATE(CA_waiting);
	DC_state= STATE(DC_idle);
}

void main()
{
	setup();
	int i;

	while (1)
	{
		US_state();
		CA_state();
		DC_state();

		for(i=0;i<100000;i++);
	}

}
