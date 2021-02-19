/*
 * main.c
 *
 *  Created on: Feb 7, 2021
 *      Author: hossam
 */
//#include "../Lib/ATmega32_Registers.h"
#include "../Lib/Bit_Math.h"
#include "../Lib/Std_Types.h"
#include "../DIO_V2/Dio_int.h"
#include "../Lcd_Driver/Lcd_int.h"
#include "../PORT_Peripheral/Port_int.h"
#include <avr/io.h>
#include "KeyPad_int.h"
#undef F_CPU
#define F_CPU 8000000
#include <util/delay.h>

int main(void){
	u8 Loc_KeyPadVal;
	Port_vidInit();
	Lcd_vidInit();

	while(1){
		Loc_KeyPadVal=Keypad_u8GetKey();
		if( ((Loc_KeyPadVal<='9') && (Loc_KeyPadVal >='0')) ||
			 Loc_KeyPadVal=='+' || Loc_KeyPadVal=='-' ||
			 Loc_KeyPadVal=='*' || Loc_KeyPadVal=='/' ||
			 Loc_KeyPadVal=='#' || Loc_KeyPadVal=='=' ){
			Lcd_u8SendPacket(Loc_KeyPadVal,LCD_u8DATA);
		}
		_delay_ms(500);
	}

	return 0;
}
