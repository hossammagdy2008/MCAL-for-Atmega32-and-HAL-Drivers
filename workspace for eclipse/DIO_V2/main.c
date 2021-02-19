/*
 * main.c
 *
 *  Created on: Jan 13, 2021
 *      Author: hossam
 */

#include "../Lib/Std_Types.h"
#include "../Lib/Bit_Math.h"

#include "../PORT_Peripheral/Port_int.h"
#include "Dio_int.h"

int main (void){
	Port_vidInit();
	Port_vidSetPinDir(Port_enuPin_16,Port_enuInput);	// PC0 = input
	Dio_vidSetPinVal(DIO_u8PIN_16,DIO_u8HIGH);			// PC0 = pull up res
	Port_vidSetPinDir(Port_enuPin_23,Port_enuOutput);	// PC7 = output
	while(1){
		if(!Dio_u8GetPinVal(DIO_u8PIN_16)){
			Dio_vidSetPinVal(DIO_u8PIN_23,DIO_u8HIGH);
		}
		else{
			Dio_vidSetPinVal(DIO_u8PIN_23,DIO_u8LOW);
		}

	}
	return 0;
}
