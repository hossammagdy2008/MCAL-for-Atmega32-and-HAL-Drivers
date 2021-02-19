/*
 * KeyPad.h
 *
 *  Created on: Feb 6, 2021
 *      Author: hossam
 */
//#include "../Lib/ATmega32_Registers.h"
#include "../Lib/Bit_Math.h"
#include "../Lib/Std_Types.h"
#include "../DIO_V2/Dio_int.h"

#undef F_CPU
#define F_CPU 8000000
#include <avr/io.h>

#include "../KeyPad_HAL/KeyPad_int.h"
#include "../KeyPad_HAL/KeyPad_priv.h"
#include "../KeyPad_HAL/KeyPad_cfg.h"

u8 KeyPad_Values_Array[4][4]={{'1','2','3','+'},{'4','5','6','-'},
							{'7','8','9','*'},{'#','0','=','/'}};


u8 Keypad_u8GetKey(void){
	u8 Loc_u8PressedKey=KEYPAD_NO_PRESSED_KEY;
	u8 Loc_u8ColValue;
	u8 row;
	u8 KEYPAD_au8ROW[4]={KEYPAD_u8ROW_0,KEYPAD_u8ROW_1,KEYPAD_u8ROW_2,KEYPAD_u8ROW_3};
for(row=0;row<4;row++){
		/*first i make all rows as high*/
		Dio_vidSetPinVal(KEYPAD_au8ROW[row],DIO_u8HIGH);
	}

	for(row=0;row<=3;row++){
		/*make a single row as low */
		Dio_vidSetPinVal(KEYPAD_au8ROW[row],DIO_u8LOW);

		Loc_u8ColValue= (Dio_u8GetPinVal(KEYPAD_u8COL_0)<<0)
						| (Dio_u8GetPinVal(KEYPAD_u8COL_1)<<1)
						| (Dio_u8GetPinVal(KEYPAD_u8COL_2)<<2)
						| (Dio_u8GetPinVal(KEYPAD_u8COL_3)<<3);
		/*check on columns */
		switch(Loc_u8ColValue){
		case COL_0_ENABLE:
			return Loc_u8PressedKey=KeyPad_Values_Array[row][COL_0];
			break;
		case COL_1_ENABLE:
			return Loc_u8PressedKey=KeyPad_Values_Array[row][COL_1];
			break;
		case COL_2_ENABLE:
			return Loc_u8PressedKey=KeyPad_Values_Array[row][COL_2];
			break;
		case COL_3_ENABLE:
			return Loc_u8PressedKey=KeyPad_Values_Array[row][COL_3];
			break;
		default :
			break;
		}
		/*return that single row to high then all back to high */
		Dio_vidSetPinVal(KEYPAD_au8ROW[row],DIO_u8HIGH);
	}
	return Loc_u8PressedKey;
}







