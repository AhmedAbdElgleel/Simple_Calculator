/*
 ====================================================================================================
 Name        : main.c
 Author      : Ahmed Abd Elgleel
 Date        : 23 Aug 2023
 ======================================================================================================
 */
#include"STD_TYPES.h"
#include"GPIO_Interface.h"
#include"keypad_interface.h"
#include"LCD_interface.h"
#include<util/delay.h>
#include "keypad_config.h"


int main() {
	uint8 PressedKey=KPD_NO_PRESSED_KEY, i = 0, Operator=0;
	sint32 num1 = 0, num2 = 0;
	LCD_Init();					/*Initialize The LCD*/
	KPD_Init();					/*Initialize The KPD*/

	while (1)
	{
		PressedKey = KPD_GetPressedKey();
		if (PressedKey != KPD_NO_PRESSED_KEY)
		{
			/*---------------------this mean that the pressed key is number----------------*/

			if (PressedKey >= '0' && PressedKey <= '9')
				{
					LCD_voidSendData(PressedKey);
					num1 = num1 * 10 + (PressedKey - '0');

				}

			/*----------------this mean that pressed key is Operator---------*/
			if ((PressedKey == '+') || (PressedKey == '-') ||  (PressedKey == '*') || (PressedKey == '/') )
				{
					num2 = num1;
					num1 = 0;
					LCD_voidSendData(PressedKey);
					Operator = PressedKey;
				}
			/*------------if the pressed key is equal lets do the mathimatical operation ---------------*/
			if (PressedKey == '=')
			{

				LCD_voidSendData(PressedKey);
				i++;
				switch (Operator)
				{
				case '+':										/*if operator is + then perform addition operation*/
					LCD_voidSendNumber(num1 + num2);
					break;
				case '-':

					LCD_voidSendNumber(num2 - num1);			/*if operator is - then perform addition operation*/
					break;
				case '*':

					LCD_voidSendNumber(num1 * num2);			/*if operator is * then perform addition operation*/
					break;
				case '/':

					LCD_voidSendFloat((1.0*num2)/num1);			/*if operator is / then perform addition operation*/
					break;
				}
			}
			i++;
			/*-------------------- if the pressed key is c lets clear the LCD ---------------------*/
			if (PressedKey == 'c')
			{
				LCD_voidClearScreen();
				num1 = 0;
				num2 = 0;
				i = 0;

			}

		}

	}

}
