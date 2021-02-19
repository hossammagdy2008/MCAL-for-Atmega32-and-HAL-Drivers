/*
 * Led.h
 *
 *  Created on: Jan 31, 2021
 *      Author: hossam
 */
#ifndef LCD_INT_H_
#define LCD_INT_H_

#define LCD_u8COMMAND		1
#define LCD_u8DATA			2
#define	LCD_u8CURSOR_SHIFT_LEFT			0x10
#define	LCD_u8CURSOR_SHIFT_RIGHT		0x14
#define LCD_u8DISPLAY_SHIFT_LEFT		((u8)0x18U)
#define LCD_u8DISPLAY_SHIFT_RIGHT		((u8)0x1CU)

#define LCD_u8GOTO_ROW_1				0x80	// 0b1000 0000
#define LCD_u8GOTO_ROW_2				0xC0	// 0b1100 0000

#define LCD_u8WRITE_AT_CGRAM			((u8)0x40U)

/*Lcd clear command
 *	write 1 in DB0
 * */
#define LCD_DISPLAY_CLEAR				0x01

/*the defines here should be in private*/

/*set F=0 then 5x7 dots
*set N=1 then 2 lines working
*DL=1	8 bit mode
*/
#define	LCD_FUNCTION_SET		0x38
/*Display ON or OFF
 *B=1	cursor blinks
 *C=1	cursor displays
 *D=1	display on
 * */
#define LCD_DISPLAY_CONTROL		0x0f
/*Entry mode set
 *DB2=1
 *DB1=1	set move direction of the cursor DB1=I/D=1 increase
 *increase is moving right
 *S=0	display won't shift
 * */
#define LCD_ENTRY_MODE			0x06

/*will never read so it will be only write on LCD*/

void Lcd_vidInit(void);

u8 Lcd_u8SendPacket(u8 Copy_u8Packet,u8 Copy_u8Type);

u8 Lcd_u8WriteString(const char *string);

u8 Lcd_u8GoTo(u8 row,u8 col);

u8 Lcd_u8SaveCustomChar(u8 Index,u8 *Char);

u8 Lcd_u8PrintCustomChar(u8 Index);

#endif /* LCD_INT_H_ */

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
