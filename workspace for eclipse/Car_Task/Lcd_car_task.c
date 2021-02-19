/*
 * Motor_Keypad_LCD_1.c
 *
 *  Created on: Feb 9, 2021
 *      Author: hossam
 */
#include "../Lib/Std_Types.h"
#include "../Lib/Bit_Math.h"
#include "../Lib/Std_Types.h"

#include "../KeyPad_HAL/KeyPad_int.h"
#include "../PORT_Peripheral/PORT_int.h"
#include "Lcd_int.h"
#include "../LED_DriverV1/HAL/LED_Driver/Led_int.h"
#include "Motor_int.h"

#undef F_CPU
#define F_CPU 8000000
#include <util/delay.h>

u8 car[8]={
		0b00000000,
		0b00011111,
		0b00010101,
		0b00011111,
		0b00011111,
		0b00011011,
		0b00011011,
		0b00000000};

u8 carcrash[8]={
		0b00000000,
		0b00010001,
		0b00010001,
		0b00011111,
		0b00010101,
		0b00011111,
		0b00000000,
		0b00000000};



int main(void){

	u8 j=0;
	u8 i=0;
	u8 stop_flag=1;
	u8 Loc_PressedKey=0;

	Port_vidInit();
	Lcd_vidInit();

	while (stop_flag){
		Loc_PressedKey=Keypad_u8GetKey();
		if(Loc_PressedKey=='6'){
			Loc_PressedKey=0;
			j++;
			DC_Motor_vidTurnRight();
			if (j>=15){
				/*crash pattern*/
				Led_vidTurnOnLed(Led_enuId_0);
				j=15;
				stop_flag=0;
			}
		}
		else if(Loc_PressedKey=='4'){
			Loc_PressedKey=0;
			j--;
			DC_Motor_vidTurnLeft();
			if (j<=1){
				/*crash pattern*/
				Led_vidTurnOnLed(Led_enuId_0);
				j=0;
				stop_flag=0;
			}
		}
		Lcd_u8SendPacket(LCD_DISPLAY_CLEAR,LCD_u8COMMAND);
		_delay_ms(1.5); // should add this delay in LCD driver
		if(stop_flag==1){
		Lcd_u8SaveCustomChar(0,car);
		i=0;
		}
		else if(stop_flag==0){
		Lcd_u8SaveCustomChar(1,carcrash);
		i=1;
		}
		Lcd_u8GoTo(1,j);
		Lcd_u8PrintCustomChar(i);
		_delay_ms(50);

	}

	return 0;
}

