/*
 * Port_init.h
 *
 *  Created on: Jan 17, 2021
 *      Author: hossam
 */

#ifndef PORT_INT_H_
#define PORT_INT_H_

typedef enum{
// PINS SW rep
	Port_enuPin_0,
	Port_enuPin_1,
	Port_enuPin_2,
	Port_enuPin_3,
	Port_enuPin_4,
	Port_enuPin_5,
	Port_enuPin_6,
	Port_enuPin_7,
	Port_enuPin_8,
	Port_enuPin_9,
	Port_enuPin_10,
	Port_enuPin_11,
	Port_enuPin_12,
	Port_enuPin_13,
	Port_enuPin_14,
	Port_enuPin_15,
	Port_enuPin_16,
	Port_enuPin_17,
	Port_enuPin_18,
	Port_enuPin_19,
	Port_enuPin_20,
	Port_enuPin_21,
	Port_enuPin_22,
	Port_enuPin_23,
	Port_enuPin_24,
	Port_enuPin_25,
	Port_enuPin_26,
	Port_enuPin_27,
	Port_enuPin_28,
	Port_enuPin_29,
	Port_enuPin_30,
	Port_enuPin_31
}Port_tenuPinId;

typedef enum {
	Port_enuOutput,
	Port_enuInput
}Port_tenuPinDir;

typedef enum {
	Port_enuOutputHigh,
	Port_enuOutputLow,
	Port_enuInputHighImpedance,
	Port_enuInputPullUp
}Port_tenuPinMode;

void Port_vidInit(void);

void Port_vidSetPinDir(Port_tenuPinId Copy_enuPinId, Port_tenuPinDir Copy_enuPinDir);

void Port_vidSetPinMode(Port_tenuPinId Copy_enuPinId, Port_tenuPinMode Copy_enuPinMode);


#endif /* PORT_INT_H_ */
