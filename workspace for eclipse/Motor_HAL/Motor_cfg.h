/*
 * Motor_cfg.h
 *
 *  Created on: Feb 9, 2021
 *      Author: hossam
 */

#ifndef MOTOR_CFG_H_
#define MOTOR_CFG_H_

#define DC_MOTOR_u8DIRECTION	1
#define DC_MOTOR_u8ON_OFF		2

#define DC_MOTOR_u8CONTROL_MODE		DC_MOTOR_u8ON_OFF

#if DC_MOTOR_u8CONTROL_MODE==DC_MOTOR_u8DIRECTION
#define DC_MOTOR_u8PIN_1	DIO_u8PIN_31
#define DC_MOTOR_u8PIN_2	DIO_u8PIN_30

#elif DC_MOTOR_u8CONTROL_MODE==DC_MOTOR_u8ON_OFF

#define DC_MOTOR_u8PIN_1	DIO_u8PIN_31

#endif


#endif /* MOTOR_CFG_H_ */
