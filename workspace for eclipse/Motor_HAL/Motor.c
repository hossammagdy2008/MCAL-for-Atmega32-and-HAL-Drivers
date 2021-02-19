/*
 * Motor.c
 *
 *  Created on: Feb 6, 2021
 *      Author: hossam
 */
#include "../Lib/Std_Types.h"
#include "../Lib/Bit_Math.h"

#include "../DIO_V2/Dio_int.h"

#undef F_CPU
#define F_CPU 8000000
#include <util/delay.h>

#include "Motor_int.h"
#include "Motor_cfg.h"

#if DC_MOTOR_u8CONTROL_MODE==DC_MOTOR_u8DIRECTION

void DC_Motor_vidTurnRight(void){

	Dio_vidSetPinVal(DC_MOTOR_u8PIN_1,DIO_u8HIGH);
	Dio_vidSetPinVal(DC_MOTOR_u8PIN_2,DIO_u8LOW);

}

void DC_Motor_vidTurnLeft(void){
	Dio_vidSetPinVal(DC_MOTOR_u8PIN_1,DIO_u8LOW);
	Dio_vidSetPinVal(DC_MOTOR_u8PIN_2,DIO_u8HIGH);
}

void DC_Motor_vidTurnOff(void){

	Dio_vidSetPinVal(DC_MOTOR_u8PIN_1,DIO_u8LOW);
	Dio_vidSetPinVal(DC_MOTOR_u8PIN_2,DIO_u8LOW);
}

void DC_Motor_vidBreak(void){

	Dio_vidSetPinVal(DC_MOTOR_u8PIN_1,DIO_u8HIGH);
	Dio_vidSetPinVal(DC_MOTOR_u8PIN_2,DIO_u8HIGH);

}

#elif DC_MOTOR_u8CONTROL_MODE==DC_MOTOR_u8ON_OFF

void DC_Motor_vidTurnOn(void){

	Dio_vidSetPinVal(DC_MOTOR_u8PIN_1,DIO_u8HIGH);
}

void DC_Motor_vidTurnOff(void){
	Dio_vidSetPinVal(DC_MOTOR_u8PIN_1,DIO_u8LOW);
}

#endif



