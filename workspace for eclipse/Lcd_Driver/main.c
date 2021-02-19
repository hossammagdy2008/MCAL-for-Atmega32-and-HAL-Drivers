/*
 * main.c
 *
 *  Created on: Jan 31, 2021
 *      Author: hossam
 */
#include "../Lib/Std_Types.h"
#include "../Lib/Bit_Math.h"

#include <util/delay.h>
#include "../PORT_Peripheral/Port_int.h"
#include "Lcd_int.h"
u8 lane[8]={
		0b00000000,
		0b00000000,
		0b00000000,
		0b00000000,
		0b00000000,
		0b00000000,
		0b00000000,
		0b00011111};
u8 human[8]={
		0b00001110,
		0b00001110,
		0b00001110,
		0b00010101,
		0b00000100,
		0b00011111,
		0b00010101,
		0b00000000};
u8 Botladder[8]={
		0b00000011,
		0b00000110,
		0b00001100,
		0b00011000,
		0b00000000,
		0b00000000,
		0b00000000,
		0b00000000};
u8 Upperladder[8]={
		0b00000000,
		0b00000000,
		0b00000000,
		0b00000011,
		0b00000110,
		0b00001100,
		0b00011000,
		0b00000000};


u8 char1[8]={
		0b00000000,
		0b00000000,
		0b00000000,
		0b00011100,
		0b00000011,
		0b00011111,
		0b00000000,
		0b00000000};

u8 char2[8]={
		0b00000000,
		0b00000000,
		0b00000000,
		0b00010101,
		0b00010101,
		0b00011111,
		0b00000000,
		0b00000000};

u8 char3[8]={
		0b00001000,
		0b00001000,
		0b00001000,
		0b00001000,
		0b00001000,
		0b00001111,
		0b00000000,
		0b00000000};

u8 char4[8]={
		0b00000000,
		0b00000000,
		0b00001111,
		0b00001001,
		0b00001111,
		0b00010000,
		0b00010000,
		0b00000000};


int main(void){
	u8 i,j,column=0,row=0;
	Port_vidInit();
	Lcd_vidInit();

	Lcd_u8SaveCustomChar(0,lane);  			// lane pattern
	Lcd_u8SaveCustomChar(1,human); 			// human pattern
	//Lcd_u8SaveCustomChar(2,Botladder); 		// Botladder
	//Lcd_u8SaveCustomChar(3,Upperladder);	// Upperladder

	while(1){
		for(j=0;j<2;j++){	// this shows the lanes
			for(i=0;i<16;i++){
				Lcd_u8GoTo(j,i);
				Lcd_u8PrintCustomChar(0);
				if (((i==1) && (j==3))){
					//Lcd_u8PrintCustomChar(2); //Botladder
				}
				/*else if (((i==0) && (j==4))){
					Lcd_u8PrintCustomChar(3); // topladder

				}*/
				else {
					Lcd_u8PrintCustomChar(0);
				}
			}
		}
		Lcd_u8GoTo(row,column);		// 1st human
		Lcd_u8PrintCustomChar(1);
		column++;
		Lcd_u8GoTo(row,column-3);	// 2nd human
		Lcd_u8PrintCustomChar(1);
		if(column==16){
			column=0;
			row++;
			if(row==2){
				row=0;
			}
		}
		_delay_ms(300);
	}

	//Write حسام in arabic
/*
	Lcd_u8SaveCustomChar(1,char4);
	Lcd_u8SaveCustomChar(2,char3);
	Lcd_u8SaveCustomChar(3,char2);
	Lcd_u8SaveCustomChar(4,char1);

	Lcd_u8GoTo(1,5);

	for(i=1;i<5;i++){
		Lcd_u8PrintCustomChar(i);
	}
*/

	//write HOSSAM
	/*
	Lcd_u8GoTo(0,4);
	Lcd_u8SendPacket('H',LCD_u8DATA);
	Lcd_u8WriteString("OSSAM IS ");
	Lcd_u8GoTo(1,5); // row 1 col 0
	Lcd_u8WriteString("SAYIN HI!!!");
	*/
	return 0;
}
