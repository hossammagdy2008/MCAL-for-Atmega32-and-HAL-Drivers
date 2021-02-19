/*
 * LED_int.h
 *
 *  Created on: Jan 20, 2021
 *      Author: hossam
 */

#ifndef LED_INT_H_
#define LED_INT_H_

typedef enum{
// PINS SW rep
	Led_enuId_0,
	Led_enuId_1,
	Led_enuId_2,
	Led_enuId_3,
	Led_enuId_4,
	Led_enuId_5,
	Led_enuId_6,
	Led_enuId_7,
	Led_enuId_8,
	Led_enuId_9
}Led_tenuId;

/* if u want to add a function that but the value as on or off regarding the inputs
typedef enum {
	Led_enuOn,
	Led_enuOff
}Led_tenuVal;
*/

/*functions here*/

//void Led_vidInit(void);

void Led_vidTurnOnLed(Led_tenuId Copy_enuLedId);

void Led_vidTurnOffLed(Led_tenuId Copy_enuLedId);

void Led_vidTglLed(Led_tenuId Copy_enuLedId);

#endif /* LED_INT_H_ */
