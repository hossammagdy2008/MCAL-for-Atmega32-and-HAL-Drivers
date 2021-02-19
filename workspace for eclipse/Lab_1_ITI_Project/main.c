/*
 * main.c
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
	u8 SegArr[10]={
			0b11000000,/*Element Zero "Pattern of Num 0 in 7 Seg"*/
			0b11111001,/*Element one  "Pattern of Num 1 in 7 Seg"*/
			0b10100100,/*Element two  "Pattern of Num 2 in 7 Seg"*/
			0b10110000,/*Element three"Pattern of Num 3 in 7 Seg"*/
			0b10011001,/*Element four "Pattern of Num 4 in 7 Seg"*/
			0b10010010,/*Element five "Pattern of Num 5 in 7 Seg"*/
			0b10000010,/*Element six  "Pattern of Num 6 in 7 Seg"*/
			0b10111000,/*Element seven"Pattern of Num 7 in 7 Seg"*/
			0b10000000,/*Element eight"Pattern of Num 8 in 7 Seg"*/
			0b10010000/*Element nine "Pattern of Num 9 in 7 Seg"*/
	};


	DDRA=0b11111111;
	while(1)	// infinite  loop for the project to run forever
	{
		/*In case of common Anode*/
		/*7 6 5 4 3 2 1 0*/

	/*	  C g f e d c b a*/	/*C is common 1 for Anode 0 for Cathode*/
/*0		  1 1 0 0 0 0 0 0*/ /*common Anode*/
/*1		  1 1 1 1 1 0 0 1*/
/*2		  1 0 1 0 0 1 0 0*/
/*3		  1 0 1 1 0 0 0 0*/
/*4		  1 0 0 1 1 0 0 1*/
/*5		  1 0 0 1 0 0 1 0*/
/*6		  1 0 0 0 0 0 1 0*/
/*7		  1 0 1 1 1 0 0 0*/
/*8		  1 0 0 0 0 0 0 0*/
/*9		  1 0 0 1 0 0 0 0*/

/*3		  0 1 0 0 1 1 1 1*/	/*common Cathod*/

		for(count=0;count<10;count++){
			PORTA=SegArr[count];
			_delay_ms(1000);
		}
	}

	return 0;
}

/*for(count=0;count<99;count++){
 * for(i=0;i<10;i++){		// 1000/4ms=255 etiration for 1 sec
 * 	PORTA= SegArr[(count/10)];
 *	PORTB=0x01;
 *	_delay_ms(2);
 *	PORTA= SegArr[(count%10)];
 *	PORTB=0x02;
 *	_delay_ms(2);
 *	}
 *}
 *
 *
 *
 *
 *
 *
 *
 *
 * */
