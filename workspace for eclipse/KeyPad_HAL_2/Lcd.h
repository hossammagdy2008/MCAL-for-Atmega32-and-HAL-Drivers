/*
 * Led.h
 *
 *  Created on: Jan 31, 2021
 *      Author: hossam
 */
#ifndef LCD_H_
#define LCD_H_

#define LCD_u8COMMAND		1
#define LCD_u8DATA			2


/*will never read so it will be only write on LCD*/

void Lcd_vidInit(void);

u8 Lcd_u8SendPacket(u8 Copy_u8Packet,u8 Copy_u8Type);

u8 Lcd_u8WriteString(const char *string);

u8 Lcd_u8GoTo(u8 row,u8 col);

u8 Lcd_u8SaveCustomChar(u8 Index,u8 *Char);

u8 Lcd_u8PrintCustomChar(u8 Index);

#endif /* LCD_H_ */

/*
 * u8 Lcd_u8CustomCharH(u8 *msg);
 * u8 Lcd_u8CustomCharH(u8 *msg){
	u8 i;
	u8 temp=0;
	//iam pointing at CGRAM
	Lcd_u8SendPacket(LCD_u8WRITE_AT_CGRAM,LCD_u8COMMAND);
	for(i=0;i<8;i++){
		temp=LCD_u8WRITE_AT_CGRAM+*msg;
		Lcd_u8SendPacket(temp,LCD_u8DATA);
		msg++;
	}
 	 return 0;
}
 * */


/* trying to make the CGRAM func
u8 Lcd_u8GoToCGRAM(u8 row,u8 col);
u8 Lcd_u8GoToCGRAM(u8 row,u8 col){
	switch(row){
		case 0:
			Lcd_u8SendPacket((0x40+col),LCD_u8COMMAND);
		break;
		default:
			return 1; // wrong param
		break;
	}
	return 0;
}*/
