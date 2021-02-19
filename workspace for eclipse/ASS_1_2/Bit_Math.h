/*
 * Bit_Math.h
 *
 *  Created on: Jan 2, 2021
 *      Author: hossam
 */

#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(Reg,Bit)			(Reg) |= ((1)<<(Bit))
#define CLR_BIT(Reg,Bit)			(Reg) &=~((1)<<(Bit))
#define TGL_BIT(Reg,Bit)  			(Reg) ^= ((1)<<(Bit))

#define GET_BIT(Reg,Bit)			(Reg>>Bit) & (1)

#define ASSIGN_REG(Reg,Value)		(Reg)=(Value)		// assign value to a Reg
#define ASSIGN_NIB_HIGH(Reg,Value)	(Reg)=((Value)&(0xf0))|((Reg)&(0x0f))	// only the 4 high bits
#define ASSIGN_NIB_LOW(Reg,Value)	(Reg)=((Value)&(0x0f))|((Reg)&(0xf0))

#define SET_REG(Reg)				(Reg)=(Reg)|(0xff)	// all values inside that Reg is 1
#define RST_REG(Reg)				(Reg)=(Reg)&(0x00)	// all values inside that Reg is zero

#define SET_NIB_HIGH(Reg)			(Reg)=((Reg)&(0xf0))|((Reg)&(0x0f))	// only the 4 high bits
#define SET_NIB_LOW(Reg)			(Reg)=((Reg)&(0x0f))|((Reg)&(0xf0))
#define RST_NIB_HIGH(Reg)			(Reg)=((Reg)&(0x0f))	// only the 4 high bits
#define RST_NIB_LOW(Reg)			(Reg)=((Reg)&(0xf0))

#define GET_NIB_HIGH(Reg)			(((Reg)>>4) & 0x0f)		// only the 4 high bits
#define GET_NIB_LOW(Reg)			((Reg) & 0x0f)		// nibble NIBBLE is = 4 bits

#define ROT_REG_RIGHT(Reg,Step)		(Reg)=(((Reg)>>Step)|((Reg)<<(8-Step)))
#define ROT_REG_LEFT(Reg,Step)		(Reg)=(((Reg)<<Step)|((Reg)>>(8-Step)))

#endif /* BIT_MATH_H_ */
