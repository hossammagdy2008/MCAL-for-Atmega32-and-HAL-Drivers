/*
 * Lcd_priv.h
 *
 *  Created on: Jan 31, 2021
 *      Author: hossam
 */


#ifndef LCD_PRIV_H_
#define LCD_PRIV_H_

#define	LCD_u8CURSOR_SHIFT_LEFT			0x10
#define	LCD_u8CURSOR_SHIFT_RIGHT		0x14
#define LCD_u8DISPLAY_SHIFT_LEFT		((u8)0x18U)
#define LCD_u8DISPLAY_SHIFT_RIGHT		((u8)0x1CU)

#define LCD_u8GOTO_ROW_1				0x80	// 0b1000 0000
#define LCD_u8GOTO_ROW_2				0xC0	// 0b1100 0000

#define LCD_u8WRITE_AT_CGRAM			((u8)0x40U)

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
/*Lcd clear command
 *	write 1 in DB0
 * */
#define LCD_DISPLAY_CLEAR		0x01
/*Entry mode set
 *DB2=1
 *DB1=1	set move direction of the cursor DB1=I/D=1 increase
 *increase is moving right
 *S=0	display won't shift
 * */
#define LCD_ENTRY_MODE			0x06


#define BIT7	7
#define BIT6	6
#define BIT5	5
#define BIT4	4
#define BIT3	3
#define BIT2	2
#define BIT1	1
#define BIT0	0



#endif /* LCD_PRIV_H_ */
