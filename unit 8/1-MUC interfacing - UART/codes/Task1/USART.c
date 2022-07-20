/*
 * USART.c
 *
 * Created: 7/18/2022 1:08:00 PM
 *  Author: momen
 */ 

 //-----------------------------------------------------------------------------------
 //includes
 //-----------------------------------------------------------------------------------

 #include "Include/USART.h"

 //===================================================================================

 /**==================================================================================
 * @Fn				-MCAL_USART_Init
 * @brief 			-Initialize USART in full duplex asynchronous normal speed mode with 8_bit frame with no parity and one stop bit at 9600 baud rate
 * @param [in] 		-None
 * @retval 			-None
 * Note				-None
 */
void MCAL_USART_Init ()
{
	UBRRL = 0x33;
	SET_BIT(UCSRB,TXEN);
	SET_BIT(UCSRB,RXEN);
}

 /**==================================================================================
 * @Fn				-MCAL_USART_SEND_CHAR
 * @brief 			-Send a char type data
 * @param [in] 		-data: char to be sent
 * @retval 			-None
 * Note				-None
 */
 
 void MCAL_USART_SEND_CHAR (char data)
 {
	 while(RD_BIT(UCSRA,UDRE)==0);
	 UDR = data;
 }
 
  /**==================================================================================
 * @Fn				-MCAL_USART_RECV_CHAR
 * @brief 			-receive a char type data
 * @param [in] 		-None
 * @retval 			-received char
 * Note				-None
 */
 
char MCAL_USART_RECV_CHAR ()
 {
	while(RD_BIT(UCSRA,RXC)==0);
	return UDR;
 }
 
  /**==================================================================================
 * @Fn				-MCAL_USART_SEND_INT
 * @brief 			-Send an integer type data
 * @param [in] 		-data: integer to be sent
 * @retval 			-None
 * Note				-None
 */
 
void MCAL_USART_SEND_INT (int data)
 {
	 char *p = &data;
	 MCAL_USART_SEND_CHAR(p[0]);
	 MCAL_USART_SEND_CHAR(p[1]);
	 MCAL_USART_SEND_CHAR(p[2]);
	 MCAL_USART_SEND_CHAR(p[3]);
 }
 
  /**==================================================================================
 * @Fn				-MCAL_USART_RECV_INT
 * @brief 			-receive an integer type data
 * @param [in] 		-None
 * @retval 			-received integer
 * Note				-None
 */
 
int MCAL_USART_RECV_INT ()
 {
	 int x;
	 char *p = &x;
	 p[0] = MCAL_USART_RECV_CHAR();
	 p[1] = MCAL_USART_RECV_CHAR();
	 p[2] = MCAL_USART_RECV_CHAR();
	 p[3] = MCAL_USART_RECV_CHAR();
	 return x;
 }
 
 /**==================================================================================
 * @Fn				-MCAL_USART_SEND_STR
 * @brief 			-Send a string of characters
 * @param [in] 		-data: pointer to lateral string or array of characters
 * @retval 			-None
 * Note				-None
 */
 
void MCAL_USART_SEND_STR (char* data)
 {
	while(*data!= 0)
	{
		MCAL_USART_SEND_CHAR(*data++);
	}
 }
 
 /**==================================================================================
 * @Fn				-MCAL_USART_RECV_STR
 * @brief 			-receive a string of characters and store it in static array of characters
 * @param [in] 		-data: pointer to array of characters
 * @retval 			-pointer to stored string
 * Note				-None
 */
 
char* MCAL_USART_RECV_STR (char* data)
 {
	char* temp = data;
	char c ;
	while((c= MCAL_USART_RECV_CHAR())!= 0x0D)
	{
		if(c== 0x08)
		{
			if(temp>data) *(--temp) = 0;
		}
		else *temp++ = c;
	}
	*temp = 0;
	return data;
 }