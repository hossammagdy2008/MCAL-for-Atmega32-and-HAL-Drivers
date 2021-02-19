/*
 * main.c
 *
 *  Created on: Jan 19, 2021
 *      Author: hossam
 */


#include "../Lib/Std_Types.h"
#include "../Lib/Bit_Math.h"
#include <avr/io.h>
#include <util/delay.h>
#define F_CPU 8000000
#include "Port_int.h"


int main(void)
{
	Port_vidInit();
	return 0;
}

