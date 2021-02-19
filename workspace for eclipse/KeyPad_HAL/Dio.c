/*
 * DIO.c
 *
 *  Created on: Jan 13, 2021
 *      Author: hossam
 */
#include "../Lib/Std_Types.h"
//#include "../Lib/ATmega32_Registers.h"
#include "../Lib/Bit_Math.h"

#include <avr/io.h>
#undef F_CPU
#define F_CPU 8000000

#include "../DIO_V2/Dio_int.h"

void Dio_vidSetPinVal(u8 Copy_u8SwPinId,u8 Copy_u8SwPinVal){
	u8 Loc_u8PortId;
	u8 Loc_u8PinId;

	Loc_u8PortId = Copy_u8SwPinId /8;
	Loc_u8PinId  = Copy_u8SwPinId %8;

	switch(Loc_u8PortId){
	case 0:	//PORTA
		if(Copy_u8SwPinVal==DIO_u8HIGH)
		{
			SET_BIT(PORTA,Loc_u8PinId);
		}
		else
		{
			CLR_BIT(PORTA,Loc_u8PinId);
		}
	break;
	case 1:	//PORTB
		if(Copy_u8SwPinVal==DIO_u8HIGH)
		{
			SET_BIT(PORTB,Loc_u8PinId);
		}
		else
		{
			CLR_BIT(PORTB,Loc_u8PinId);
		}
	break;
	case 2:	// PORTC
		if(Copy_u8SwPinVal==DIO_u8HIGH)
		{
			SET_BIT(PORTC,Loc_u8PinId);
		}
		else
		{
			CLR_BIT(PORTC,Loc_u8PinId);
		}
	break;
	case 3:	// PORTD
		if(Copy_u8SwPinVal==DIO_u8HIGH)
		{
			SET_BIT(PORTD,Loc_u8PinId);
		}
		else
		{
			CLR_BIT(PORTD,Loc_u8PinId);
		}
	break;
	default:
	break;
	}

}

void Dio_vidTglPinVal(u8 Copy_u8SwPinId){
	u8 Loc_u8PortId;
	u8 Loc_u8PinId;

	Loc_u8PortId = Copy_u8SwPinId /8;
	Loc_u8PinId  = Copy_u8SwPinId %8;

	switch(Loc_u8PortId){
	case 0:	//PORTA
		TGL_BIT(PORTA,Loc_u8PinId);
	break;
	case 1:	//PORTB
		TGL_BIT(PORTB,Loc_u8PinId);
	break;
	case 2:	// PORTC
		TGL_BIT(PORTC,Loc_u8PinId);
	break;
	case 3:	// PORTD
		TGL_BIT(PORTD,Loc_u8PinId);
	break;
	default:
	break;
	}
}

u8 Dio_u8GetPinVal(u8 Copy_u8SwPinId){
	u8 Loc_u8PortId;
	u8 Loc_u8PinId;

	Loc_u8PortId = Copy_u8SwPinId /8;
	Loc_u8PinId  = Copy_u8SwPinId %8;

	switch(Loc_u8PortId){
	case 0:	//PORTA
		return GET_BIT(PINA,Loc_u8PinId);
	break;
	case 1:	//PORTB
		return GET_BIT(PINB,Loc_u8PinId);
	break;
	case 2:	//PORTC
		return GET_BIT(PINC,Loc_u8PinId);
	break;
	case 3:	//PORTD
		return GET_BIT(PIND,Loc_u8PinId);
	break;
	default:
		return 0;
	break;
	}
}

