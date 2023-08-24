/*
 ================================================================================================================================
 Name        : KeyPad_program.c
 Module Name : Kepad
 Author      : Ahmed Abd Elgleel
 Date        : 21 Aug 2023
 ===================================================================================================================================
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GPIO_Interface.h"
#include "KEYPAD_config.h"
#include "KEYPAD_interface.h"

/*-------------------------------------- Getting the Pressed key from Keypad ------------------------------------*/
uint8 KPD_GetPressedKey(void) {

	uint8 pressedKey = KPD_NO_PRESSED_KEY;										/* value of the pressed key and initial has value of no pressed key */

	uint8 colCounter, rowCounter;												/* value of the counters for loops */

	uint8 pinState;																/* flag to check if the pin pressed or not */

	static uint8 kpdArr[ROW_NUM][COL_NUM] = KPD_ARR_VAL;						/* array for keypad values with specific column and row number */

	static uint8 kpdColArr[COL_NUM] = { KPD_COL_0, KPD_COL_1, KPD_COL_2,		/* array for keypad columns with specific column number */
	KPD_COL_3 };

	static uint8 kpdRowArr[ROW_NUM] = { KPD_ROW_0, KPD_ROW_1, KPD_ROW_2,		/* array for keypad rows with specific row number */
	KPD_ROW_3 };

	for (colCounter = 0; colCounter < COL_NUM; ++colCounter) {					/* start loops to check the pins state */

		GPIO_SetPinValue(KPD_COL_PORT, kpdColArr[colCounter], PIN_LOW);			/* activate current column to check it */
		for (rowCounter = 0; rowCounter < ROW_NUM; ++rowCounter) {

			GPIO_GetPinValue(KPD_ROW_PORT, kpdRowArr[rowCounter], &pinState);	/* read the value of the current row */

			if (pinState == PIN_LOW) {											/* if the value is 0 that mean the key is pressed */

				pressedKey = kpdArr[rowCounter][colCounter];					/* get the value of the key with column and row number of loop */

				while (pinState == PIN_LOW) {									/* wait until the key is released */

					GPIO_GetPinValue(KPD_ROW_PORT, kpdRowArr[rowCounter],&pinState);	/* get the same value until the key is released */
				}

				return pressedKey;												/* return the value of pressed key in the keypad */
			}
		}

		GPIO_SetPinValue(KPD_COL_PORT, kpdColArr[colCounter], PIN_HIGH);		/* deactivate current column to check the next column in the next loop */
	}

	return pressedKey;															/* return the value 0xFF which mean that no key is pressed */
}

/*----------------------------------------------- Initialization of keypad --------------------------------------------------*/
void KPD_Init(void) {
																		/* set the PORT (PORTD) output for the columns of KEYPAD */
	GPIO_SetPinDirection(KPD_COL_PORT, KPD_COL_0, OUTPUT);
	GPIO_SetPinDirection(KPD_COL_PORT, KPD_COL_1, OUTPUT);
	GPIO_SetPinDirection(KPD_COL_PORT, KPD_COL_2, OUTPUT);
	GPIO_SetPinDirection(KPD_COL_PORT, KPD_COL_3, OUTPUT);

																		/* set the PORT (PORTB) output for the rows of KEYPAD */
	GPIO_SetPinDirection(KPD_ROW_PORT, KPD_ROW_0, INPUT);
	GPIO_SetPinDirection(KPD_ROW_PORT, KPD_ROW_1, INPUT);
	GPIO_SetPinDirection(KPD_ROW_PORT, KPD_ROW_2, INPUT);
	GPIO_SetPinDirection(KPD_ROW_PORT, KPD_ROW_3, INPUT);
																		/* set all pins of KEYPAD columns high */

	GPIO_SetPortValue(KPD_COL_PORT, 0x3C);

																		/* set all pins of KEYPAD rows with internal pull-up resistor */
	GPIO_SetPortValue(KPD_ROW_PORT, 0xF0);
}
