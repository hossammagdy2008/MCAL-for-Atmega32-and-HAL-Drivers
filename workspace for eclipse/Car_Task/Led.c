/*
 * LED.c
 *
 *  Created on: Jan 20, 2021
 *      Author: hossam
 */

#include "../Lib/Std_Types.h"
#include "../Lib/Bit_Math.h"
#include "../DIO_V2/Dio_int.h"	// can i include the DIO_Int.h in the LED.c ?
#include "../LED_DriverV1/HAL/LED_Driver/Led_cfg.h"
#include "../LED_DriverV1/HAL/LED_Driver/Led_int.h"
#include "../LED_DriverV1/HAL/LED_Driver/Led_priv.h"
#include "../Lib/ATmega32_Registers.h"

//extern u8 Led_au8LedConfig[10];


void Led_vidTurnOnLed(Led_tenuId Copy_enuLedId)
{
	//Dio_vidSetPinVal(Led_au8LedConfig[Copy_enuLedId],DIO_u8HIGH);

	switch (Copy_enuLedId){
	case Led_enuId_0:
		Dio_vidSetPinVal(LED_u8ID_0,DIO_u8HIGH);
		break;
	case Led_enuId_1:
		Dio_vidSetPinVal(LED_u8ID_1,DIO_u8HIGH);
		break;
	case Led_enuId_2:
		Dio_vidSetPinVal(LED_u8ID_2,DIO_u8HIGH);
		break;
	case Led_enuId_3:
		Dio_vidSetPinVal(LED_u8ID_3,DIO_u8HIGH);
		break;
	case Led_enuId_4:
		Dio_vidSetPinVal(LED_u8ID_4,DIO_u8HIGH);
		break;
	case Led_enuId_5:
		Dio_vidSetPinVal(LED_u8ID_5,DIO_u8HIGH);
		break;
	case Led_enuId_6:
		Dio_vidSetPinVal(LED_u8ID_6,DIO_u8HIGH);
		break;
	case Led_enuId_7:
		Dio_vidSetPinVal(LED_u8ID_7,DIO_u8HIGH);
		break;
	case Led_enuId_8:
		Dio_vidSetPinVal(LED_u8ID_8,DIO_u8HIGH);
		break;
	case Led_enuId_9:
		Dio_vidSetPinVal(LED_u8ID_9,DIO_u8HIGH);
		break;
	default:
		break;
	}

}

void Led_vidTurnOffLed(Led_tenuId Copy_enuLedId)
{
	switch (Copy_enuLedId){
	case Led_enuId_0:
		Dio_vidSetPinVal(LED_u8ID_0,DIO_u8LOW);
		break;
	case Led_enuId_1:
		Dio_vidSetPinVal(LED_u8ID_1,DIO_u8LOW);
		break;
	case Led_enuId_2:
		Dio_vidSetPinVal(LED_u8ID_2,DIO_u8LOW);
		break;
	case Led_enuId_3:
		Dio_vidSetPinVal(LED_u8ID_3,DIO_u8LOW);
		break;
	case Led_enuId_4:
		Dio_vidSetPinVal(LED_u8ID_4,DIO_u8LOW);
		break;
	case Led_enuId_5:
		Dio_vidSetPinVal(LED_u8ID_5,DIO_u8LOW);
		break;
	case Led_enuId_6:
		Dio_vidSetPinVal(LED_u8ID_6,DIO_u8LOW);
		break;
	case Led_enuId_7:
		Dio_vidSetPinVal(LED_u8ID_7,DIO_u8LOW);
		break;
	case Led_enuId_8:
		Dio_vidSetPinVal(LED_u8ID_8,DIO_u8LOW);
		break;
	case Led_enuId_9:
		Dio_vidSetPinVal(LED_u8ID_9,DIO_u8LOW);
		break;
	default:
		break;
	}
}

void Led_vidTglLed(Led_tenuId Copy_enuLedId)
{
	switch (Copy_enuLedId){
	case Led_enuId_0:
		Dio_vidTglPinVal(LED_u8ID_0);
		break;
	case Led_enuId_1:
		Dio_vidTglPinVal(LED_u8ID_1);
		break;
	case Led_enuId_2:
		Dio_vidTglPinVal(LED_u8ID_2);
		break;
	case Led_enuId_3:
		Dio_vidTglPinVal(LED_u8ID_3);
		break;
	case Led_enuId_4:
		Dio_vidTglPinVal(LED_u8ID_4);
		break;
	case Led_enuId_5:
		Dio_vidTglPinVal(LED_u8ID_5);
		break;
	case Led_enuId_6:
		Dio_vidTglPinVal(LED_u8ID_6);
		break;
	case Led_enuId_7:
		Dio_vidTglPinVal(LED_u8ID_7);
		break;
	case Led_enuId_8:
		Dio_vidTglPinVal(LED_u8ID_8);
		break;
	case Led_enuId_9:
		Dio_vidTglPinVal(LED_u8ID_9);
		break;
	default:
		break;
	}
}








