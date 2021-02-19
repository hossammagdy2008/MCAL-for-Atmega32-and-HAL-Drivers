/*
 * main.c
 *		#stop watch ASS_2_2
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
	u8 count=0;
	u8 count_temp=0;
	u8 i;
	u8 RstPressed_Button=0;
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
		if(!(GET_BIT(PINA,0))){	// its pressed the button connected to GND
			_delay_ms(20);		// for the debouncing issue
			if(!(GET_BIT(PINA,0))){
				for(count=0;count<=60;count++){
					count_temp=count;
					for(i=0;i<205;i++)	// 960/4ms=240 etiration for 1 sec}
					{// that what should it be but i have tested it
						// with my stopwatch and its a little bit slower
							// bec of the instructions cyc should be around
							// 205 instead of 240
						PORTD= SegArr[(count/10)];
						PORTC=0x01;
						_delay_ms(2);
						PORTD= SegArr[(count%10)];
						PORTC=0x02;
						_delay_ms(2);
						if(!(GET_BIT(PINA,1))){
							_delay_ms(20); //debouncing
							if(!(GET_BIT(PINA,1))){
								break;
							}
						}
					}
					if(!(GET_BIT(PINA,1))){
						RstPressed_Button=1;
						break;
					}
				}
			}
		}
		else{	// if i didnt press on start
			PORTD=SegArr[(count_temp/10)];
			PORTC=0x01;
			_delay_ms(2);
			PORTD=SegArr[(count_temp%10)];
			PORTC=0x02;
			_delay_ms(2);
			if(GET_BIT(PINA,1)){
				RstPressed_Button=2;
				}
			if((!(GET_BIT(PINA,1)))&&(RstPressed_Button==2)){
				// its pressed the button connected to GND
				_delay_ms(20);	// for the debouncing issue
				RstPressed_Button=0;
				if(!(GET_BIT(PINA,1))){
					while((GET_BIT(PINA,0))){
							PORTD=SegArr[0];
							PORTC=0x01;
							_delay_ms(2);
							PORTD=SegArr[0];
							PORTC=0x02;
							_delay_ms(2);
							count_temp=0;
						}
					}
				}
		}
	}
	return 0;
}

/*
DDRA =0b11111110;
PORTA=0b10011110;
PINA=0b1001111?;
*/




