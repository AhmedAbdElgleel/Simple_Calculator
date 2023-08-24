/*
 ============================================================================
 Name        : KeyPad_interface.h
 Author      : Ahmed Abd Egleel
 Date        : 21 Aug 2023
 ============================================================================
 */

#ifndef KEYPAD_INTERFACE_H_
#define KEYPAD_INTERFACE_H_

uint8 KPD_GetPressedKey(void);		/*Return the pressed key from Keypad*/

void KPD_Init(void);				/*Initialization the ports of keypad*/

#endif /* KEYPAD_INTERFACE_H_ */
