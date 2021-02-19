/*
 * KeyPad_int.h
 *
 *  Created on: Feb 6, 2021
 *      Author: hossam
 */

#ifndef KEYPAD_INT_H_
#define KEYPAD_INT_H_

#define KEYPAD_NO_PRESSED_KEY				0xFF
#define	LCD_u8CLEAR_SCREEN_CMD				((u8)0x01U)



u8 Keypad_u8GetKey(void);

#endif /* KEYPAD_INT_H_ */


