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

int main(void){
	u8 Loc_PW[4]={'1','2','3','4'};
	u8 Loc_PressedKet[4];
	u8 Loc_KeyPressed=0;
	u8 i=0,j=0,k=0;
	u8 PW_flag=1;
	u8 false_flag=1;

	Port_vidInit();
	Lcd_vidInit();

	Lcd_u8WriteString("Welcome Back");
	_delay_ms(3000);

	for(i=0;((i<3) && (false_flag!=0));i++){
		/*please enter ur PW */
		/*if still false_flge==1 please enter ur PW */
		Lcd_u8SendPacket(LCD_DISPLAY_CLEAR,LCD_u8COMMAND);
		Lcd_u8GoTo(0,1);
		Lcd_u8WriteString("Please Enter PW");
		Lcd_u8GoTo(1,5);
		/*i have only 3 times to try*/
		for(j=0;j<4;j++){
			/*i need to read 4 digits*/
			while(PW_flag){
				/*read the keypad*/
				Loc_PressedKet[j]=Keypad_u8GetKey();
				/*keypad input between 0 to 9*/
				if((Loc_PressedKet[j]>='0') && (Loc_PressedKet[j]<='9')){
					/*print * everytime user enter digit*/
					Lcd_u8SendPacket('*',LCD_u8DATA);
					/*reset PW_Flag to break while loop*/
					PW_flag=0;
				}
			}
			/*set PW_Flag again to enter the next digit*/
			PW_flag=1;
			_delay_ms(500); // wait until i press the button
		}
		false_flag=4;
		for(k=0;k<4;k++){
			if((Loc_PressedKet[k]==Loc_PW[k])){
				false_flag-=1;
				// k=0 flag=3,k=1 flag=2 ,k=2 flag=1 ,k=3 flag=0
			}
		}
	}

	if(false_flag==0){
		Lcd_u8GoTo(0,0);
		Lcd_u8WriteString("1-Fan    2-Lamp1");
		Lcd_u8GoTo(1,0);
		Lcd_u8WriteString("3-Lamp2  4-Lamp3");
	}
	else if (false_flag!=0){
		Lcd_u8GoTo(0,0);
		Lcd_u8WriteString("System Locked");
		Lcd_u8GoTo(1,0);
		Lcd_u8WriteString("Try Again Later");


	}

	while ((false_flag==0)){
		Loc_KeyPressed=Keypad_u8GetKey();
		if(Loc_KeyPressed=='1'){
			DC_Motor_vidTurnOn();
			Lcd_u8GoTo(0,0);
			Lcd_u8WriteString("1-F_On");
		}
		else if(Loc_KeyPressed=='5'){
			DC_Motor_vidTurnOff();
			Lcd_u8GoTo(0,0);
			Lcd_u8WriteString("1-FOff");
		}
		else if(Loc_KeyPressed=='2'){
			Led_vidTurnOnLed(Led_enuId_0);
			Lcd_u8GoTo(0,8);
			Lcd_u8WriteString("2-L1_On");
		}
		else if(Loc_KeyPressed=='6'){
			Led_vidTurnOffLed(Led_enuId_0);
			Lcd_u8GoTo(0,8);
			Lcd_u8WriteString("2-L1Off");
		}
		else if(Loc_KeyPressed=='3'){
			Led_vidTurnOnLed(Led_enuId_1);
			Lcd_u8GoTo(1,0);
			Lcd_u8WriteString("3-L2_On");
		}
		else if(Loc_KeyPressed=='7'){
			Led_vidTurnOffLed(Led_enuId_1);
			Lcd_u8GoTo(1,0);
			Lcd_u8WriteString("3-L2Off");
		}
		else if(Loc_KeyPressed=='4'){
			Led_vidTurnOnLed(Led_enuId_2);
			Lcd_u8GoTo(1,8);
			Lcd_u8WriteString("4-L3_On");
		}
		else if(Loc_KeyPressed=='8'){
			Led_vidTurnOffLed(Led_enuId_2);
			Lcd_u8GoTo(0,8);
			Lcd_u8WriteString("4-L3Off");
		}
		//_delay_ms(500); // wait until i press the button
	}


	return 0;
}

