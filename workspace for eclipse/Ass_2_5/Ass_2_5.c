/*
 * Ass_2_5.c
 *	# Love Story Assignment
 *  Created on: Jan 6, 2021
 *      Author: hossam
 */

#include "../Lib/Std_Types.h"
#include "../Lib/Bit_Math.h"
#include <avr/io.h>
#define F_CPU 8000000
#include <util/delay.h>

u8 RowArr[8]={
	0b00000001,
	0b00000010,
	0b00000100,
	0b00001000,
	0b00010000,
	0b00100000,
	0b01000000,
	0b10000000
};
u8 ColArr[3][8]={
{
  0b10111101,
  0b00111101,
  0b00111101,
  0b10111000,
  0b10111101,
  0b00011000,
  0b01011010,
  0b11111111
},{
  0b11011101,
  0b10011101,
  0b10010000,
  0b11001101,
  0b11011101,
  0b10001000,
  0b10101010,
  0b11111111
},{
  0b10111101,
  0b01011010,
  0b01100110,
  0b01111110,
  0b10111101,
  0b11011011,
  0b11100111,
  0b11111111
}};
/*

u8 ColArr[8]={
	{
		0b10111101,
		0b01011010,
		0b01100110,
		0b01111110,
		0b10111101,
		0b11011011,
		0b11100111,
		0b11111111
		}
};
 * */

int main (void)
{
	u8 loopCount;
	u8 ImagCount;
	u8 DisplayCount;

	SET_REG(DDRA);	// set PORTA all pins are output
	SET_REG(DDRD);	// set PORTD all Pins are output
	while(1)
	{
		for(ImagCount=0;ImagCount<3;ImagCount++){
			for(DisplayCount=0;DisplayCount<100;DisplayCount++){
				for(loopCount=0;loopCount<8;loopCount++)
				{
					ASSIGN_REG(PORTA,RowArr[loopCount]);
					ASSIGN_REG(PORTD,ColArr[ImagCount][loopCount]);
					_delay_ms(2);
					SET_REG(PORTD);
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


