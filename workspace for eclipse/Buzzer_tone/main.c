/*
 * main.c
 *
 *  Created on: Jan 3, 2021
 *      Author: hossam
 */
// back 1 time (../) then enter lib (Lib/)
#include "../Lib/Std_Types.h"
#include "../Lib/Bit_Math.h"
#include <avr/io.h>
#define F_CPU 8000000
#include <util/delay.h>


int main (void)
{	SET_BIT(DDRA,0); // set PA0 output

	while(1)
	{
		/*Set PA0 as High "5 volt"*/
		SET_BIT(PORTA,0);
		/*delay for 200usec*/	// check the bouncing mechanism
		_delay_us(120);
		/*Set PA0 as Low "0 volt"*/
		CLR_BIT(PORTA,0);
		_delay_us(120);
	}


	return 0;
}

/*
DDRA =0b11111110;
PORTA=0b10011110;
PINA=0b1001111?;
*/


