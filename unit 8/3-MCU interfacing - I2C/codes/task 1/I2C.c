/*
 * I2C.c
 *
 * Created: 7/24/2022 10:27:31 AM
 *  Author: momen
 */ 

#include "Include/I2C.h"
#define	F_CPU 8000000UL

 /**==================================================================================
 * @Fn				-MCAL_I2C_Init
 * @brief 			-Initialize I2C according to Specified Parameter
 * @param [in] 		-mode: according to @ref I2C_MODE_define
 * @param [in] 		-bitrate: 400k max
 * @param [in] 		-address: used only when initialized as slave
 * @retval 			-None
 * Note				-None
 */
 
void MCAL_I2C_Init(uint8_t mode, uint32_t bitrate, uint8_t address)
 {
	 if(mode) TWAR = address;
	 else TWBR=(unsigned char) (((F_CPU/bitrate)-16)/2);
 }
 
   /**==================================================================================
 * @Fn				-MCAL_I2C_Write
 * @brief 			-send the data with I2C
 * @param [in] 		-data: to send 
 * @retval 			-status register to check 
 * Note				-None
 */
 
uint8_t MCAL_I2C_Write(uint8_t mode, uint8_t data)
 {
	 if(mode)
	 {
		 TWCR = TWINT | TWEA | TWEN;
		 while ((TWCR & TWINT) == 0);
		 while (TWSR != SLAVE_SLA_R_ACK_RECEIVE);
	 }

	 while ((TWCR & TWINT) == 0);
	 TWDR = data;
	 TWCR = TWINT | TWEN;
	 while ((TWCR & TWINT) == 0);
	 return TWSR;
 }
 
    /**==================================================================================
 * @Fn				-MCAL_I2C_Read
 * @brief 			-receive the data with I2C
 * @param [in] 		-data: pointer to save data received 
 * @retval 			-status register to check 
 * Note				-None
 */
 
uint8_t MCAL_I2C_Read(uint8_t mode, uint8_t* data)
 {
	 if(mode)
	 {
		TWCR = TWINT | TWEA | TWEN;
		while ((TWCR & TWINT) == 0);
		while (TWSR != SLAVE_SLA_W_ACK_RECEIVE);		 
	 }
	 
	 TWCR = TWINT | TWEA | TWEN;
	 while ((TWCR & TWINT) == 0);
	 
	 if(mode) while (TWSR != SLAVE_DATA_ACK_RECEIVE);
	 else while (TWSR != MASTER_DATA_ACK_RECEIVE);
	 
	 *data = TWDR;
	 return TWSR;
 }
 
 void MCAL_I2C_Start(void)
 {
	 TWCR = TWINT | TWSTA | TWEN;
	 while ((TWCR & TWINT) == 0);
	 while (TWSR != MASTER_START_SUCCESS);
 }

 void MCAL_I2C_Stop()
 {
	 TWCR = TWINT | TWSTO | TWEN;
 }