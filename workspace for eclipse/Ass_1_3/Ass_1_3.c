/*
 * main.c
 * task of fuzzy connections wit hthe next Pattern
 *	a-b-g-e-d-c-g-f
 *	a-f-g-c-d-e-g-b
 *	a
 *
 *  Created on: Jan 2, 2021
 *      Author: hossam
 */
#include <avr/io.h>
#define F_CPU 8000000
#include <util/delay.h> 	// to be able to use the delay function

#include "Std_Types.h"
#include "Bit_Math.h"

int main (void)
{
	u8 count;
	u8 i;
	u8 SegArr1[8]={
			/*a-b-g-e-d-c-g-f
			 *a-f-g-c-d-e-g-b
			 *a*/
			/*Cgfedcba*/
			0b11111110,/*Element a "Pattern of Num 0 in 7 Seg"*/
			0b11111101,/*Element b  "Pattern of Num 1 in 7 Seg"*/
			0b10111111,/*Element g  "Pattern of Num 2 in 7 Seg"*/
			0b11101111,/*Element e"Pattern of Num 3 in 7 Seg"*/
			0b11110111,/*Element d "Pattern of Num 4 in 7 Seg"*/
			0b11111011,/*Element c "Pattern of Num 5 in 7 Seg"*/
			0b10111111,/*Element g  "Pattern of Num 6 in 7 Seg"*/
			0b11011111,/*Element f"Pattern of Num 7 in 7 Seg"*/
	};
	u8 SegArr2[8]={
				/*a-b-g-e-d-c-g-f
				 *a-f-g-c-d-e-g-b
				 *a*/
				/*Cgfedcba*/
				0b11111110,/*Element a "Pattern of Num 0 in 7 Seg"*/
				0b11011111,/*Element f  "Pattern of Num 1 in 7 Seg"*/
				0b10111111,/*Element g  "Pattern of Num 2 in 7 Seg"*/
				0b11111011,/*Element c"Pattern of Num 3 in 7 Seg"*/
				0b11110111,/*Element d "Pattern of Num 4 in 7 Seg"*/
				0b11101111,/*Element e "Pattern of Num 5 in 7 Seg"*/
				0b10111111,/*Element g  "Pattern of Num 6 in 7 Seg"*/
				0b11111101,/*Element b"Pattern of Num 7 in 7 Seg"*/
		};

	DDRC=0xff;
	DDRD=0xff;	//PORTA & PORT B Are OutPut Pins
	while(1)			// infinite  loop for the project to run forever
	{
		PORTC=0x02;	// light the 1st 7 seg
		for(count=0;count<=7;count++){
			for(i=0;i<255;i++)		// 1000/4ms=255 etiration for 1 sec}
			{
				PORTD= SegArr1[count];
				_delay_ms(4);
			}
		}

		PORTC=0x01;	// light the 2nd 7 seg
		for(count=0;count<=7;count++){
			for(i=0;i<255;i++)		// 1000/4ms=255 etiration for 1 sec}
			{
				PORTD= SegArr2[count];
				_delay_ms(4);
			}
		}
	}
return 0;
}
