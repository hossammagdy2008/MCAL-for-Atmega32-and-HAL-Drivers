/*
 * Led.c
 *
 *  Created on: Jan 31, 2021
 *      Author: hossam
 */

#include "../Lib/Std_Types.h"
#include "../Lib/Bit_Math.h"

#include "../DIO_V2/Dio_int.h"

#undef F_CPU
#define F_CPU 8000000
#include <util/delay.h>

#include "Lcd_int.h"
#include "Lcd_priv.h"
#include "Lcd_cfg.h"

/*intialize all the functions here*/

void Lcd_vidInit(void){
	//#ifdef LCD_8BIT_MODE

	_delay_ms(30);	// intialization according to the DataSheet

	/*RS & R/W both must be zero 1st
	 * and it will be done in the Lcd_u8SendPacket function*/
	//	Dio_vidSetPinVal(LCD_u8RS_PIN,LCD_u8COMMAND);
	//	Dio_vidSetPinVal(LCD_u8RW_PIN,LCD_u8WRITE);
	/*send the Function Set Reg to intialize the LCD
	 *DL=1 8 bit mode
	 *N=1  2 line display
	 *F=0  Font 5*7 dots
	 * */
	Lcd_u8SendPacket( LCD_FUNCTION_SET , LCD_u8COMMAND);
	_delay_us(39);
	/*send the display control mode
	 *B=1	cursor blinks
	 *C=1	cursor displays
	 *D=1	display on */
	Lcd_u8SendPacket( LCD_DISPLAY_CONTROL , LCD_u8COMMAND);
	_delay_us(39);
	/*send the Display clear Command
	 * */
	Lcd_u8SendPacket( LCD_DISPLAY_CLEAR , LCD_u8COMMAND);
	_delay_ms(1.53);
	/*send the entry mode
	 * */
	Lcd_u8SendPacket( LCD_ENTRY_MODE , LCD_u8COMMAND);
	//#ifdef LCD_4BIT_MODE
	/*intialize the 4 bit mode here*/
}


u8 Lcd_u8SendPacket(u8 Copy_u8Packet,u8 Copy_u8Type){
	if(Copy_u8Type==LCD_u8COMMAND){
		Dio_vidSetPinVal(LCD_u8RS_PIN,LCD_COMMAND);
		Dio_vidSetPinVal(LCD_u8RW_PIN,LCD_u8WRITE);
		Dio_vidSetPinVal(LCD_u8EN_PIN,DIO_u8HIGH);
		Dio_vidSetPinVal(LCD_u8D7_PIN,GET_BIT(Copy_u8Packet,BIT7));
		Dio_vidSetPinVal(LCD_u8D6_PIN,GET_BIT(Copy_u8Packet,BIT6));
		Dio_vidSetPinVal(LCD_u8D5_PIN,GET_BIT(Copy_u8Packet,BIT5));
		Dio_vidSetPinVal(LCD_u8D4_PIN,GET_BIT(Copy_u8Packet,BIT4));
		Dio_vidSetPinVal(LCD_u8D3_PIN,GET_BIT(Copy_u8Packet,BIT3));
		Dio_vidSetPinVal(LCD_u8D2_PIN,GET_BIT(Copy_u8Packet,BIT2));
		Dio_vidSetPinVal(LCD_u8D1_PIN,GET_BIT(Copy_u8Packet,BIT1));
		Dio_vidSetPinVal(LCD_u8D0_PIN,GET_BIT(Copy_u8Packet,BIT0));
		_delay_us(50); // wait until the data reach the LCD
		Dio_vidSetPinVal(LCD_u8EN_PIN,DIO_u8LOW); // then close enable to start reading
		_delay_us(50);// reading time is 43 us
	}
	else if(Copy_u8Type==LCD_u8DATA){
		Dio_vidSetPinVal(LCD_u8RS_PIN,LCD_DATA);
		Dio_vidSetPinVal(LCD_u8RW_PIN,LCD_u8WRITE);
		Dio_vidSetPinVal(LCD_u8EN_PIN,DIO_u8HIGH);
		Dio_vidSetPinVal(LCD_u8D7_PIN,GET_BIT(Copy_u8Packet,BIT7));
		Dio_vidSetPinVal(LCD_u8D6_PIN,GET_BIT(Copy_u8Packet,BIT6));
		Dio_vidSetPinVal(LCD_u8D5_PIN,GET_BIT(Copy_u8Packet,BIT5));
		Dio_vidSetPinVal(LCD_u8D4_PIN,GET_BIT(Copy_u8Packet,BIT4));
		Dio_vidSetPinVal(LCD_u8D3_PIN,GET_BIT(Copy_u8Packet,BIT3));
		Dio_vidSetPinVal(LCD_u8D2_PIN,GET_BIT(Copy_u8Packet,BIT2));
		Dio_vidSetPinVal(LCD_u8D1_PIN,GET_BIT(Copy_u8Packet,BIT1));
		Dio_vidSetPinVal(LCD_u8D0_PIN,GET_BIT(Copy_u8Packet,BIT0));
		_delay_us(50); // wait until the data reach the LCD
		Dio_vidSetPinVal(LCD_u8EN_PIN,DIO_u8LOW); // then close enable to start reading
		_delay_us(50);// reading time is 43 us
	}
	else {
		return 1; // wrong param
	}
	return 0;
}


u8 Lcd_u8WriteString(const char *string){
	/*string is a pointer to array of characters
	 * points to the 1st place in this array (1st charc)
	 * then i send it character by character
	 * */
	while((*string) != '\0'){
		Lcd_u8SendPacket((*string),LCD_u8DATA); //string[i] [] is like*
		string++;
	}

	return 0;
}


u8 Lcd_u8GoTo(u8 row,u8 col){
	/**/
	switch(row){
	case 0:
		Lcd_u8SendPacket((LCD_u8GOTO_ROW_1+col),LCD_u8COMMAND);
		break;
	case 1:
		Lcd_u8SendPacket((LCD_u8GOTO_ROW_2+col),LCD_u8COMMAND);
		break;
	default:
		return 1; // wrong param
		break;
	}
	return 0;
}


u8 Lcd_u8SaveCustomChar(u8 Index,u8 *Char){
	u8 i;
	/*CGRAM is 64 x 8 bit RAM
	 * every char is 8*5 and to write every char needs 8 bytes
	 * 64 place each place is a byte / 8 bytes (for 1 char)
	 *total number of char that can be stored in CGRAM = 8 {0 -> 7}
	 * */
	if(Index<8)
	{
		Lcd_u8SendPacket((LCD_u8WRITE_AT_CGRAM + (Index*8)),LCD_u8COMMAND);
		/* Command 0x40 + the location to write in CGRAM address */
		for(i=0;i<8;i++)
			/* Write 8 byte for generation of 1 character */
			Lcd_u8SendPacket(Char[i],LCD_u8DATA);
	}
	return 0;
}

u8 Lcd_u8PrintCustomChar(u8 Index){

	Lcd_u8SendPacket(Index,LCD_u8DATA);
	return 0;
}


