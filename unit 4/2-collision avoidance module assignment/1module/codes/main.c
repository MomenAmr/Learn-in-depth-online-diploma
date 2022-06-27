/*
 * main.c
 *
 *  Created on: Jun 20, 2022
 *      Author: momen
 */


#include"CA.h"

extern void (*state)();

void setup()
{
	state = STATE(waiting);
}

void main()
{
	setup();
	int i;

	while (1)
	{
		state();

		for(i=0;i<100000;i++);
	}

}
