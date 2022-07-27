/*
 * SPI.c
 *
 * Created: 7/21/2022 11:05:25 AM
 *  Author: momen
 */ 
 //-----------------------------------------------------------------------------------
 //includes
 //-----------------------------------------------------------------------------------

 #include "Include/SPI.h"

 //===================================================================================
 
 /**==================================================================================
 * @Fn				-MCAL_SPI_Init
 * @brief 			-Initialize SPI according to Specified Parameter
 * @param [in] 		-mode: according to @ref SPI_MODE_define
 * @param [in] 		-speed: according to @ref SPI_SPEED_define
 * @param [in] 		-polarity: according to @ref SPI_CLOCK_define
 * @param [in] 		-phase: according to @ref SPI_SAMPLE_define
 * @retval 			-None
 * Note				-None
 */
 void MCAL_SPI_Init (uint8_t mode, uint8_t speed, uint8_t polarity, uint8_t phase)
 {
	 uint8_t temp = (mode | phase | polarity | (0x03 & speed));
	 SPI->SPCR = temp;
	 SPI->SPSR = (speed >> 2);
	 
	 if(mode)
	 {
		 	MCAL_GPIO_Init(GPIOB, GPIO_PIN_4,MODE_OUTPUT_PP);
		 	MCAL_GPIO_Init(GPIOB, GPIO_PIN_5,MODE_OUTPUT_PP);
		 	MCAL_GPIO_Init(GPIOB, GPIO_PIN_7,MODE_OUTPUT_PP);
	 }
	 else MCAL_GPIO_Init (GPIOB, GPIO_PIN_6,MODE_OUTPUT_PP);
	 
	 SPI_EN;
 }
 
  /**==================================================================================
 * @Fn				-MCAL_SPI_TRANSEIV
 * @brief 			-send the master data or receive the slave data
 * @param [in] 		-data: to send by master if needed
 * @retval 			-received by slave if needed
 * Note				-None
 */
  
 uint8_t MCAL_SPI_TRANSEIV (uint8_t data)
 {
		 SPI->SPDR = data;
		 while ((SPI->SPSR & 0x80) == 0);
		 return SPI->SPDR;
 }
