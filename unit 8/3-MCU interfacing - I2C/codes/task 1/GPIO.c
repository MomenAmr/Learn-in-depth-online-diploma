/*
 * GPIO.c
 *
 * Created: 7/17/2022 7:41:40 AM
 *  Author: momen
 */ 
 
 //-----------------------------------------------------------------------------------
 //includes
 //-----------------------------------------------------------------------------------

 #include "Include/GPIO.h"

 //===================================================================================
 
 /**==================================================================================
 * @Fn				-MCAL_GPIO_Init
 * @brief 			-Initialize GPIOx PINy according to Specified Parameter
 * @param [in] 		-GPIOx: where x can be A, B, C, D to select the GPIO peripheral
 * @param [in] 		-Pin: is the specified GPIO pin to configure according to @ref GPIO_PIN_define
 * @param [in] 		-mode: is the specified mode for pin to configure according to @ref GPIO_MODE_define
 * @retval 			-None
 * Note				-None
 */
 
 void MCAL_GPIO_Init (GPIO_t* GPIOx , uint8_t pin, uint8_t mode)
 {
	 switch (mode)
	 {
		 case MODE_INPUT_FLO :
		 GPIOx->DDR &= ~pin; 
		 break;
		 
		 case MODE_INPUT_PU :
		 GPIOx->DDR &= ~pin;
		 GPIOx->PORT |= pin;
		 PUR_EN;
		 break;
		 
		 case MODE_OUTPUT_PP :
		 GPIOx->DDR |= pin;
		 break;
	 }
	
 }
 
 /**==================================================================================
 * @Fn				-MCAL_GPIO_DeInit
 * @brief 			-reset GPIOx according to Specified Parameter
 * @param [in] 		-GPIOx: where x can be A, B, C, D to select the GPIO peripheral
 * @retval 			-None
 * Note				-None
 */
 
 void MCAL_GPIO_DeInit(GPIO_t* GPIOx)
 {
	GPIOx->DDR = 0x00;
	GPIOx->PIN = 0x00;
	GPIOx->PORT = 0x00;
 }
 
 /**==================================================================================
 * @Fn				-MCAL_GPIO_READ_PIN
 * @brief 			-Read Specific Pin
 * @param [in] 		-GPIOx: where x can be A, B, C, D to select the GPIO peripheral
 * @param [in] 		-Pin: is the specified GPIO pin to configure according to @ref GPIO_PIN_define
 * @retval 			-the Pin Value According to @ref GPIO_PIN_state
 * Note				-None
 * */
 
 uint8_t MCAL_GPIO_READ_PIN (GPIO_t* GPIOx , uint8_t pin)
 {
	 return (GPIOx->PIN & pin);
 }
 
 /**==================================================================================
 * @Fn				-MCAL_GPIO_TOGGLE_PIN
 * @brief 			-toggle Specific Pin
 * @param [in] 		-GPIOx: where x can be A, B, C, D to select the GPIO peripheral
 * @param [in] 		-Pin: is the specified GPIO pin to configure according to @ref GPIO_PIN_define
 * @retval 			-None
 * Note				-None
 * */
 
 void MCAL_GPIO_TOGGLE_PIN (GPIO_t* GPIOx , uint8_t pin)
 {
	 GPIOx->PORT ^= pin;
 }
 
 
 /**==================================================================================
 * @Fn				-MCAL_GPIO_WRITE_PIN
 * @brief 			-write on Specific Pin
 * @param [in] 		-GPIOx: where x can be A, B, C, D to select the GPIO peripheral
 * @param [in] 		-Pin: is the specified GPIO pin to configure according to @ref GPIO_PIN_define
 * @param [in] 		-value: the Pin Value According to @ref GPIO_PIN_state
 * @retval 			-None
 * Note				-None
 * */
 
void MCAL_GPIO_WRITE_PIN (GPIO_t* GPIOx , uint8_t pin, uint8_t value)
 {
	 if(value == PIN_LOW) GPIOx->PORT &= ~pin;
	 else if(value == PIN_HIGH) GPIOx->PORT |= pin;
 }
 
 /**==================================================================================
 * @Fn				-MCAL_GPIO_READ_PORT
 * @brief 			-Read Specific Port
 * @param [in] 		-GPIOx: where x can be A, B, C, D to select the GPIO peripheral
 * @retval 			-the Port Value in hex format
 * Note				-None
 * */
 
 uint8_t MCAL_GPIO_READ_PORT (GPIO_t* GPIOx)
 {
	 return (GPIOx->PIN);
 }
 
 /**==================================================================================
 * @Fn				-MCAL_GPIO_WRITE_PORT
 * @brief 			-write on Specific Port
 * @param [in] 		-GPIOx: where x can be A, B, C, D to select the GPIO peripheral
 * @param [in] 		-value: the Port Value in hex format
 * @retval 			-None
 * Note				-None
 * */
 
void MCAL_GPIO_WRITE_PORT (GPIO_t* GPIOx , uint8_t value)
 {
	 GPIOx->PORT = value;
 }
 
 
 /**==================================================================================
 * @Fn				-MCAL_GPIO_WRITE_PORT_SEL
 * @brief 			-write on Specific pins on specific Port
 * @param [in] 		-GPIOx: where x can be A, B, C, D to select the GPIO peripheral
 * @param [in] 		-mask: the Port selective mask according to @ref GPIO_MASK_define
 * @param [in] 		-value: the Port Value in hex format
 * @retval 			-None
 * Note				-None
 * */
 
void MCAL_GPIO_WRITE_PORT_SEL (GPIO_t* GPIOx , uint8_t mask , uint8_t value)
 {
	GPIOx->PORT |= (mask & value);
	GPIOx->PORT &= ~(mask & ~value);
}