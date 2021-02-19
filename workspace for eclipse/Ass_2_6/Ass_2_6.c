/*
 * Ass_2_6.c
 *	#Snake Game
 *  Created on: Jan 7, 2021
 *      Author: hossam
 */


#include "../Lib/Std_Types.h"
#include "../Lib/Bit_Math.h"
#include <avr/io.h>
#define F_CPU 8000000
#include <util/delay.h>

u8 LightRowArr[8]={
	0b00000001,
	0b00000010,
	0b00000100,
	0b00001000,
	0b00010000,
	0b00100000,
	0b01000000,
	0b10000000
};
u8 LightColArr[8]={
	0b11111110,
	0b11111101,
	0b11111011,
	0b11110111,
	0b11101111,
	0b11011111,
	0b10111111,
	0b01111111
};

int main (void)
{
	u8 loopCount;
	u8 ImagCount;
	u8 DisplayCount;
	u8 Col_Counter=2;	// i start with a length of 3 then counter is 2
	u8 Row_Counter=3;	// i start at row number 4 so i count from 4
	u8 Light_Row=4;
	u8 Light_Col=0;
	u8 a=0; // start from col 0
	u8 b=2;	// till col 2  light 3 coloms  0,1,2
	SET_REG(DDRA);	//set PORTA all pins are output
	SET_REG(DDRD);	// set PORTD all Pins are output
	PORTA=3;		// intialize the snake with a length of 3 dots
					// by lighting row 3
	CLR_REG(DDRC);	// set PORTC as input PORT
	SET_REG(PORTC); // PORTC use Pull up res
	while(1)
	{
		for(DisplayCount=0;DisplayCount<100;DisplayCount++){
			for(loopCount=a;loopCount<=b;loopCount++)
			{
				if(a==6){
					ASSIGN_REG(PORTD,LightColArr[0]);
					ASSIGN_REG(PORTA,LightRowArr[Row_Counter]);
				}
				else if (a==7){
					ASSIGN_REG(PORTD,LightColArr[0]);
					ASSIGN_REG(PORTA,LightRowArr[Row_Counter]);
					_delay_ms(2);
					SET_REG(PORTD);
					ASSIGN_REG(PORTD,LightColArr[1]);
					ASSIGN_REG(PORTA,LightRowArr[Row_Counter]);
				}
				_delay_ms(2);
				SET_REG(PORTD);
				ASSIGN_REG(PORTD,LightColArr[loopCount]);
				ASSIGN_REG(PORTA,LightRowArr[Row_Counter]);
				Col_Counter++;	// to know which colom does it stop at
				if (Col_Counter==8){Col_Counter=0;}//0-7 coloms
				_delay_ms(2);
				SET_REG(PORTD);
			}
		}
		a++;	// a & b to make the snake loop back over the wall
		if(a==8){a=0;b=2;}
		b++;
		if(b==8){b=7;}

		if(!(GET_BIT(PINC,0))){	// DOWN Push Button
			a=Row_Counter;
			b=Row_Counter+2;
			if(!(GET_BIT(PINC,0))){
			for(DisplayCount=0;DisplayCount<100;DisplayCount++){
				for(loopCount=a;loopCount<=b;loopCount++)
				{
					if(a==6){
						ASSIGN_REG(PORTD,LightColArr[Col_Counter]);
						ASSIGN_REG(PORTA,LightRowArr[0]);
					}
					else if (a==7){
						ASSIGN_REG(PORTD,LightColArr[Col_Counter]);
						ASSIGN_REG(PORTA,LightRowArr[0]);
						_delay_ms(2);
						SET_REG(PORTD);
						ASSIGN_REG(PORTD,LightColArr[Col_Counter]);
						ASSIGN_REG(PORTA,LightRowArr[1]);
					}
					_delay_ms(2);
					SET_REG(PORTD);
					ASSIGN_REG(PORTD,LightColArr[Col_Counter]);
					ASSIGN_REG(PORTA,LightRowArr[loopCount]);
					Row_Counter++;	// to know which colom does it stop at
					if (Row_Counter==8){Row_Counter=0;}//0-7 coloms
					_delay_ms(2);
					SET_REG(PORTD);
				}
			}
			a++;	// a & b to make the snake loop back over the wall
			if(a==8){a=0;b=2;}
			b++;
			if(b==8){b=7;}
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




