/*
 * main.c
 *
 *  Created on: Jan 20, 2021
 *      Author: hossam
 */

#include "../../Lib/Std_Types.h"
#include "../../Lib/Bit_Math.h"
#include "../MCAL/PORT_Peripheral/Port_int.h"
#include "../HAL/LED_Driver/Led_int.h"
#undef F_CPU
#define F_CPU 8000000
#include <util/delay.h>



int main(void){

	Port_vidInit();	// intialize port prephiral
	/* set pindir of portA0 as output*/
	//Port_vidSetPinDir(Port_enuPin_0,Port_enuOutput);// why i cant use LED_u8ID_0 is it bec i deal with the port driver here ?
	while (1){
		Led_vidTglLed(Led_enuId_0);	// use Led driver to tgl PIN0 at PORTA
		_delay_ms(1000);

	}

	return 0;
}


