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
{
	/*declare variable name switch_state to ge the state of the switch*/
	/*values are ->0 "Pressed"*/
	/*values are ->1 "Released"*/
	u8 switch_state;
	/*set PA0 as Input*/
	CLR_BIT(DDRA,0);	//PA0 INPUT

	SET_BIT(PORTA,0);	//pull up resistor in PA0

	SET_BIT(DDRA,7);	// PA7 output

	CLR_BIT(PORTA,7);	// output low at PA7

	while(1){
		/*Read the siwtch value*/
		switch_state=GET_BIT(PINA,0);
		/*check if the switch is pressed or not*/
		if(switch_state==0){
			/*the switch is pressed , so turn on the led*/
			SET_BIT(PORTA,7);
		}
		else {
			/*the switch is released , so turn off the led*/
			CLR_BIT(PORTA,7);
		}
	}


	return 0;
}

/*
DDRA =0b11111110;
PORTA=0b10011110;
PINA=0b1001111?;
*/


/*my keypad the right 4 PINS are for coloms & the left 4 for rows
 * coloms should be high and rows low if i use pull up res
 * */

