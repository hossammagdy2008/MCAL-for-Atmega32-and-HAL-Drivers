/*
 * main.c
 *	# piano Assignment
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
	DDRC=0xff;	// PORTD  is OutPut Pins
	PORTC=0;	// intialize the output for PORTD is zero

	DDRA=0x00;	// PORTA is an input PORT
	PORTA=0xff;	// PORTA use pull up resistors
	while(1)
	{
	while((!(GET_BIT(PINA,0))) || (!(GET_BIT(PINA,1))) || (!(GET_BIT(PINA,2)))
	||	(!(GET_BIT(PINA,3))) || (!(GET_BIT(PINA,4))) || (!(GET_BIT(PINA,5)))
	||	(!(GET_BIT(PINA,6))) || (!(GET_BIT(PINA,7)))){
		if ( !(GET_BIT(PINA,0)) ){// Do 523251 HZ = 2Microsec
		/*Set PA0 as High "5 volt"*/
		SET_BIT(PORTC,7);
		/*delay for 200usec*/	// check the bouncing mechanism
		_delay_us(1);
		/*Set PA0 as Low "0 volt"*/
		CLR_BIT(PORTC,7);
		_delay_us(1);
		}
		else if( !(GET_BIT(PINA,1))){ //Re 58733 HZ = 17Microsec
			SET_BIT(PORTC,7);
			_delay_us(8);
			CLR_BIT(PORTC,7);
			_delay_us(9);
		}
		else if( !(GET_BIT(PINA,2))){ //MI 659255 HZ = 1.5Microsec
				SET_BIT(PORTC,7);
				_delay_us(0.75);
				CLR_BIT(PORTC,7);
				_delay_us(0.75);
		}
		else if( !(GET_BIT(PINA,3))){ //FA 698456 HZ = 1.4Microsec
					SET_BIT(PORTC,7);
					_delay_us(0.7);
					CLR_BIT(PORTC,7);
					_delay_us(0.7);
		}
		else if( !(GET_BIT(PINA,4))){ //SOL 783991 HZ = 1.3Microsec
					SET_BIT(PORTC,7);
					_delay_us(0.65);
					CLR_BIT(PORTC,7);
					_delay_us(0.65);
		}
		else if( !(GET_BIT(PINA,5))){ //LA 880 HZ = 1millisec
					SET_BIT(PORTC,7);
					_delay_us(500);
					CLR_BIT(PORTC,7);
					_delay_us(500);
		}
		else if( !(GET_BIT(PINA,6))){ //TI 987767 HZ = 1Microsec
					SET_BIT(PORTC,7);
					_delay_us(0.5);
					CLR_BIT(PORTC,7);
					_delay_us(0.5);
		}
		else if( !(GET_BIT(PINA,7))){ //Doo 1046502 HZ = 100Microsec
					SET_BIT(PORTC,7);
					_delay_us(50);
					CLR_BIT(PORTC,7);
					_delay_us(50);
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


