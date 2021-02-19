/*
 * main.c
 *	traffic light
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
	u8 counter=0;
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
			0b10010000/*Element nine "Pattern of Num 9 in 7 Seg"*/
	};

	DDRB=0xff;
	DDRA=0b11111111;
	DDRD=0b11111111;	//PORTA & PORT B Are OutPut Pins
	while(1)			// infinite  loop for the project to run forever
	{
		counter=0;
	/*red for 10 secs then yellow + red for 5 secs then green for 20 secs*/
		for(count=0;count<=35;count++){
			PORTA=SegArr[(counter%10)];
			PORTD=SegArr[(counter/10)];
			if (count<=10){
				PORTB=0x01;
			}
			else if ((count>10) && (count<=15)){
				PORTB=0x03;
					if (count==15){
						counter=0;
					}
			}
			else if ((count>15) && (count<=35)){
				PORTB=0x04;
			}
			counter++;
			_delay_ms(1000);
		}
	}

	return 0;
}

/*for(count=0;count<99;count++){
 * for(i=0;i<10;i++){		// 1000/4ms=250 then i<10 to take 250ms //250 etiration
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
