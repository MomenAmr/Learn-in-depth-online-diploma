/*
 * GPIO.h
 *
 * Created: 7/17/2022 7:32:57 AM
 *  Author: momen
 */ 


#ifndef GPIO_H_
#define GPIO_H_

//-----------------------------------------------------------------------------------
//includes
//-----------------------------------------------------------------------------------

#include "atmega32a_device_header.h"

//===================================================================================

//-----------------------------------------------------------------------------------
//Macros configuration references
//-----------------------------------------------------------------------------------

//@ref GPIO_PIN_define
#define GPIO_PIN_0					((uint8_t)0x01)	/* pin 0 selected    */
#define GPIO_PIN_1					((uint8_t)0x02)	/* pin 1 selected    */
#define GPIO_PIN_2					((uint8_t)0x04)	/* pin 2 selected    */
#define GPIO_PIN_3					((uint8_t)0x08)	/* pin 3 selected    */
#define GPIO_PIN_4					((uint8_t)0x10)	/* pin 4 selected    */
#define GPIO_PIN_5					((uint8_t)0x20)	/* pin 5 selected    */
#define GPIO_PIN_6					((uint8_t)0x40)	/* pin 6 selected    */
#define GPIO_PIN_7					((uint8_t)0x80)	/* pin 7 selected    */

// @ref GPIO_MODE_define

#define  MODE_INPUT_FLO				((uint8_t)0x00)		/* Floating Input 						*/
#define  MODE_INPUT_PU				((uint8_t)0x01)		/* Input with pull-up 					*/
#define  MODE_OUTPUT_PP				((uint8_t)0x02)		/* General Purpose Output Push-Pull		*/

// @ref GPIO_MASK_define
#define LOWER_NIBBLE				((uint8_t)0x0F)
#define UPPER_NIBBLE				((uint8_t)0xF0)

// @ref GPIO_PIN_state
#define PIN_LOW						((uint8_t)0x00)
#define PIN_HIGH					((uint8_t)0x01)

//===================================================================================

//-----------------------------------------------------------------------------------
//APIs supported by MCAL GPIO driver
//-----------------------------------------------------------------------------------

void MCAL_GPIO_Init (GPIO_t* GPIOx , uint8_t pin, uint8_t mode);
void MCAL_GPIO_DeInit(GPIO_t* GPIOx);

uint8_t MCAL_GPIO_READ_PIN (GPIO_t* GPIOx , uint8_t pin);
void MCAL_GPIO_TOGGLE_PIN (GPIO_t* GPIOx , uint8_t pin);
void MCAL_GPIO_WRITE_PIN (GPIO_t* GPIOx , uint8_t pin, uint8_t value);

uint8_t MCAL_GPIO_READ_PORT (GPIO_t* GPIOx);
void MCAL_GPIO_WRITE_PORT (GPIO_t* GPIOx , uint8_t value);
void MCAL_GPIO_WRITE_PORT_SEL (GPIO_t* GPIOx , uint8_t mask , uint8_t value);

//===================================================================================

#endif /* GPIO_H_ */