/*
 * Led_cfg.c
 *
 *  Created on: Jan 23, 2021
 *      Author: hossam
 */

#include "../../../Lib/Std_Types.h"
#include "../../../Lib/Bit_Math.h"

#include "../../MCAL/DIO_V2/Dio_int.h"

// if we need to optimize the code in led.c

u8 Led_au8LedConfig[10]={
		DIO_u8PIN_12,  // LED_u8ID_0_PIN
		DIO_u8PIN_12,
		DIO_u8PIN_12,
		DIO_u8PIN_12,
		DIO_u8PIN_12,
		DIO_u8PIN_12,
		DIO_u8PIN_12,
		DIO_u8PIN_12,
		DIO_u8PIN_12
};


