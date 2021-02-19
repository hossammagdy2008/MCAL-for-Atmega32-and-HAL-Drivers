/*
 * main.c
 *	#Ass2_3 -2 seven seg  2 switches  inc the 7 segs
 *  Created on: Jan 4, 2021
 *      Author: hossam
 */

#include "../Lib/Std_Types.h"
#include "../Lib/Bit_Math.h"
#include <avr/io.h>
#define F_CPU 8000000
#include <util/delay.h>

int main (void)
{
	u8 count;
	u8 counter_temp_1=0;
	u8 counter_temp_2=0;
	u8 switch_state=0;
	u8 SegArr[10]={
			0b11000000,/*Element Zero "Pattern of Num 0 in 7 Seg"*/
			0b11111001,/*Element one  "Pattern of Num 1 in 7 Seg"*/
			0b10100100,/*Element two  "Pattern of Num 2 in 7 Seg"*/
			0b10110000,/*Element three"Pattern of Num 3 in 7 Seg"*/
			0b10011001,/*Element four "Pattern of Num 4 in 7 Seg"*/
			0b10010010,/*Element five "Pattern of Num 5 in 7 Seg"*/
			0b10000010,/*Element six  "Pattern of Num 6 in 7 Seg"*/
			0b11111000,/*Element seven"Pattern of Num 7 in 7 Seg"*/
			0b10000000,/*Element eight"Pattern of Num 8 in 7 Seg"*/
			0b10010000 /*Element nine "Pattern of Num 9 in 7 Seg"*/
	};


	DDRC=0xff;	// PORTC is OutPut Pins
	PORTC=0;	// intialize the output for PORTC is zero
	DDRD=0xff;	// PORTD  is OutPut Pins
	PORTD=0;	// intialize the output for PORTD is zero

	DDRA=0x00;	// PORTA is an input PORT
	PORTA=0xff;	// PORTA use pull up resistors

	while(1)
	{
		PORTD= SegArr[counter_temp_1];
		PORTC=0x01;
		_delay_ms(2);
		PORTD= SegArr[counter_temp_2];
		PORTC=0x02;
		_delay_ms(2);
		while(!(GET_BIT(PINA,0))){// if PA0 is pressed inc it
			if ( !(GET_BIT(PINA,1)) ){
				counter_temp_1--;
				if(counter_temp_1==255)// if counter_temp_1 overflowed =9
					{counter_temp_1=9;}
			}
			else {
				counter_temp_1++;
				if(counter_temp_1==10){counter_temp_1=0;}
			}

			for(count=0;count<255*3;count++)// 1000/4ms=255 etiration for 1 sec}
			{// 3*255 = 3 secs so if i pressed & hold for 3 secs it inc again
				PORTD= SegArr[counter_temp_1];
				PORTC=0x01;
				_delay_ms(2);
				PORTD= SegArr[counter_temp_2];
				PORTC=0x02;
				_delay_ms(2);
				if(GET_BIT(PINA,0)){	// if i left the pressed button get out
					break;				// PIN will be high bec of the
				}						// pull up res
			}
		}
		while(!(GET_BIT(PINA,1))){// if PA1 is pressed inc it
			if ( !(GET_BIT(PINA,0)) ){
				counter_temp_2--;
				if(counter_temp_2==255)// if counter overflowed make it =9
					{counter_temp_2=9;}
				}
				else {
					counter_temp_2++;
					if(counter_temp_2==10){counter_temp_2=0;}
				}
			for(count=0;count<255*3;count++)		// 1000/4ms=255 etiration for 1 sec}
			{
				PORTD= SegArr[counter_temp_1];
				PORTC=0x01;
				_delay_ms(2);
				PORTD= SegArr[counter_temp_2];
				PORTC=0x02;
				_delay_ms(2);
				if(GET_BIT(PINA,1)){	// if i left the pressed button get out
					break;
				}
			}
		}
	}
	return 0;
}

/*my keypad the right 4 PINS are for coloms & the left 4 for rows
 * coloms should be high and rows low if i use pull up res
 * */
