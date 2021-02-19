/*
 * main.c
 *
 *  Created on: Jan 13, 2021
 *      Author: hossam
 */

#include "../Lib/Std_Types.h"
#include "../Lib/Bit_Math.h"
#include <avr/io.h>
#include "Dio_int.h"

int main (void){
	Dio_vidSetPinDir(DIO_u8PIN_16,DIO_u8INPUT);	// PC0 = input
	Dio_vidSetPinVal(DIO_u8PIN_16,DIO_u8HIGH);	// PC0 = pull up res
	Dio_vidSetPinDir(DIO_u8PIN_23,DIO_u8OUTPUT);// PC7 = output
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
