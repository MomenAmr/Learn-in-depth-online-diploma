/*
 * SEG_7.c
 *
 *  Created on: Jul 14, 2022
 *      Author: momen
 */


#include "SEG_7.h"
#include "GPIO.h"

GPIO_PIN_CNFQ_t Pinconfig ;

void SEG_7_init()
{
	Pinconfig.PIN_NUMBER = N0;
	Pinconfig.MODE = GPIO_MODE_OUTPUT_PP;
	Pinconfig.SPEED = GPIO_SPEED_10M;
	MCAL_GPIO_Init(SEG_7, &Pinconfig);

	Pinconfig.PIN_NUMBER = N1;
	Pinconfig.MODE = GPIO_MODE_OUTPUT_PP;
	Pinconfig.SPEED = GPIO_SPEED_10M;
	MCAL_GPIO_Init(SEG_7, &Pinconfig);

	Pinconfig.PIN_NUMBER = N2;
	Pinconfig.MODE = GPIO_MODE_OUTPUT_PP;
	Pinconfig.SPEED = GPIO_SPEED_10M;
	MCAL_GPIO_Init(SEG_7, &Pinconfig);

	Pinconfig.PIN_NUMBER = N3;
	Pinconfig.MODE = GPIO_MODE_OUTPUT_PP;
	Pinconfig.SPEED = GPIO_SPEED_10M;
	MCAL_GPIO_Init(SEG_7, &Pinconfig);

	Pinconfig.PIN_NUMBER = N4;
	Pinconfig.MODE = GPIO_MODE_OUTPUT_PP;
	Pinconfig.SPEED = GPIO_SPEED_10M;
	MCAL_GPIO_Init(SEG_7, &Pinconfig);

	Pinconfig.PIN_NUMBER = N5;
	Pinconfig.MODE = GPIO_MODE_OUTPUT_PP;
	Pinconfig.SPEED = GPIO_SPEED_10M;
	MCAL_GPIO_Init(SEG_7, &Pinconfig);

	Pinconfig.PIN_NUMBER = N6;
	Pinconfig.MODE = GPIO_MODE_OUTPUT_PP;
	Pinconfig.SPEED = GPIO_SPEED_10M;
	MCAL_GPIO_Init(SEG_7, &Pinconfig);
}

void SEG_7_printnum(char c)
{
	switch(c)
	{
	case ('0') :
		MCAL_GPIO_WRITE_PORT(SEG_7, ZERO<<9);
		break;

	case ('1') :
		MCAL_GPIO_WRITE_PORT(SEG_7, ONE<<9);
		break;

	case ('2') :
		MCAL_GPIO_WRITE_PORT(SEG_7, TWO<<9);
		break;

	case ('3') :
		MCAL_GPIO_WRITE_PORT(SEG_7, THREE<<9);
		break;

	case ('4') :
		MCAL_GPIO_WRITE_PORT(SEG_7, FOUR<<9);
		break;

	case ('5') :
		MCAL_GPIO_WRITE_PORT(SEG_7, FIVE<<9);
		break;

	case ('6') :
		MCAL_GPIO_WRITE_PORT(SEG_7, SIX<<9);
		break;

	case ('7') :
		MCAL_GPIO_WRITE_PORT(SEG_7, SEVEN<<9);
		break;

	case ('8') :
		MCAL_GPIO_WRITE_PORT(SEG_7, EIGHT<<9);
		break;

	case ('9') :
		MCAL_GPIO_WRITE_PORT(SEG_7, NINE<<9);
		break;

	default :
		MCAL_GPIO_WRITE_PORT(SEG_7, NONE<<9);
	}
}
