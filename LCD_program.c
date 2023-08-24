/*
 ============================================================================
 Name        : LCD_program.c
 Author      : Ahmed Abd Elgleel
 Date        : 20 Aug 2023
 ============================================================================
 */

#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "LCD_interface.h"
#include "LCD_config.h"
#include "GPIO_Interface.h"
#include <util/delay.h>
/*------------------------------------------------ Function Definitions Of LCD ----------------------------------------------------------------*/

			   /*-------------------Function used to send a certain command to LCD--------------------------*/

void LCD_voidSendCommand(uint8 copy_uint8_command) {

	GPIO_SetPinValue(LCD_CTRL_PORT, LCD_RS_PIN, PIN_LOW);						/* set RS pin to low...RS low => command  */

	GPIO_SetPinValue(LCD_CTRL_PORT, LCD_RW_PIN, PIN_LOW);						/* set RW pin to low...RW low => write  */

	GPIO_SetPortValue(LCD_DATA_PORT, copy_uint8_command);						/* send the command to data pin in LCD */

	GPIO_SetPinValue(LCD_CTRL_PORT, LCD_EN_PIN, PIN_HIGH);						/* set enable pin to high then low to generate pulse */
	_delay_ms(2);
	GPIO_SetPinValue(LCD_CTRL_PORT, LCD_EN_PIN, PIN_LOW);
}

			/*----------------------- Function used to Send Data to LCD --------------------------------*/

void LCD_voidSendData(uint8 copy_uint8_data) {

	GPIO_SetPinValue(LCD_CTRL_PORT, LCD_RS_PIN, PIN_HIGH);						/* set RS pin to high...RS high => data  */

	GPIO_SetPinValue(LCD_CTRL_PORT, LCD_RW_PIN, PIN_LOW);						/* set RW pin to low...RW low => write  */

	GPIO_SetPortValue(LCD_DATA_PORT, copy_uint8_data);							/* send the command to data pin in LCD */

	GPIO_SetPinValue(LCD_CTRL_PORT, LCD_EN_PIN, PIN_HIGH);						/* set enable pin to high then low to generate pulse */
	_delay_ms(2);
	GPIO_SetPinValue(LCD_CTRL_PORT, LCD_EN_PIN, PIN_LOW);
}
		  /*-------------------------- Function used to Initialize The LCD as 8 bit mode ----------------------------*/

void LCD_Init(void) {

	GPIO_SetPortDirection(LCD_DATA_PORT, OUTPUT);								/* set the PORTA output for the data of LCD */

	GPIO_SetPinDirection(LCD_CTRL_PORT, LCD_RS_PIN, OUTPUT);					/* set the RS Pin in the PORT (portB as declared in config) as output for control of LCD */

	GPIO_SetPinDirection(LCD_CTRL_PORT, LCD_RW_PIN, OUTPUT);					/*set the RW Pin in the PORT (portB as declared in config) as output for control of LCD */

	GPIO_SetPinDirection(LCD_CTRL_PORT, LCD_EN_PIN, OUTPUT);					/*set the EN Pin in the PORT (portB as declared in config) as output for control of LCD */

	_delay_ms(40);																/* wait for 40ms */

	LCD_voidSendCommand(LCD_TWO_LINE_EIGHT_BIT_MODE);							/* set LCD configuration to 2 lines and 5*8 font size */

	LCD_voidSendCommand(LCD_CURSOR_OFF);										/* turn on the LCD and disable showing a cursor */

	LCD_voidSendCommand(LCD_CLEAR_DISPLAY);										/* clear display */
}

	/*----------------------------------- Function used to Display string on LCD ----------------------------------------*/

void LCD_voidDisplayString(const uint8 *uint8_str) {
	uint8 i;
		for(i=0;uint8_str[i]!='\0';i++)
			LCD_voidSendData(uint8_str[i]);
}

	/*----------------------------------- Function used to Move Cursor of LCD ----------------------------------------*/


void LCD_voidMoveCursor(uint8 copy_uint8row, uint8 copy_uint8column) {

	uint8 LCD_address = 0;										/* variable to know which address in the LCD will to cursor moved to */

	switch (copy_uint8row) {									/* check which row is chosen */
	case 0:
		LCD_address = copy_uint8column+0x00;					/* first row position is 0x00 + column*/
		break;
	case 1:

		LCD_address = copy_uint8column + 0x40;					/* second row position is 0x040 + column*/
		break;
	case 2:
		LCD_address = copy_uint8column + 0x10;					/*third row position is 0x01 + column*/

		break;
	case 3:
		LCD_address = copy_uint8column + 0x40;					/* fourth row position is 0x50 + colum*/
		break;

	}														    /*and then we should set the MSB of position by or it with 0b10000000 which is 0x80*/

	LCD_voidSendCommand(LCD_CURSOR_POSITION | LCD_address);		/* move the LCD cursor to the specific address location */
}

/*----------------------------------- Function used to display string on LCD at certain Column ----------------------------------------*/


void LCD_voiddisplayStringRowColumn(uint8 copy_row, uint8 copy_column,const uint8 *Str) {

	LCD_voidMoveCursor(copy_row, copy_column);					/* go to to the required LCD position */

	LCD_voidDisplayString(Str);									/* display the string */
}

/*----------------------------------------------- Function used to clear Screen Of LCD -----------------------------------------*/

void LCD_voidClearScreen(void) {
	LCD_voidSendCommand( LCD_DISPLAY_CLEAR);
	_delay_ms(10);
}
/*------------------------------------------- Function used to display Number on Screen ---------------------------------------*/

void LCD_voidSendNumber(sint32 copy_sint32Number) //123
{
	uint32 copy_uint32power = 1;
	sint32 copy_sint32num = copy_sint32Number;
	if (copy_sint32Number == 0) {							/*If the Result of operation = 0 then send '0' to Screen*/
		LCD_voidSendData('0');
		return;
	}
	if (copy_sint32Number < 0) {

		copy_sint32Number = copy_sint32Number * (-1);		/*If the Result of operation is less than zero which mean it is negative number ex -5 send negative sign to LCD*/
		LCD_voidSendData('-');
	}
	while (copy_sint32num) { //12345	      			   /*lets making masking for each digit in number for example no. 12345*/

		copy_sint32num = copy_sint32num / 10;      		   /*12345-->1234-->123-->12-->1-->0*/
		copy_uint32power = copy_uint32power * 10;
	}
	copy_uint32power = copy_uint32power / 10;
	while (copy_uint32power > 0) {
		copy_sint32num = copy_sint32Number / copy_uint32power;  //12345/1000=0
		copy_sint32Number %= copy_uint32power;
		copy_uint32power /= 10;

		LCD_voidSendData(copy_sint32num + '0');				 /*sending number digit by digit to LCD as char*/
	}
}

/*------------------------------------------- Function used to display float on Screen ---------------------------------------*/

void LCD_voidSendFloat(float64 copy_float64Float) {
	uint32 copy_sint32power = 1;
	sint32 copy_uint32num = copy_float64Float;
	sint32 i = 0;

	if (copy_float64Float == 0) {
		LCD_voidSendData('0');									/*If the Result of operation = 0 then send '0' to Screen*/
		return;
	}
	if (copy_float64Float < 0) {								/*If the Result of operation is less than zero which mean it is negative number ex -5 send negative sign to LCD*/

		copy_float64Float = copy_float64Float * (-1);
		LCD_voidSendData('-');
	}
	while (copy_uint32num)
	{
		copy_uint32num = copy_uint32num / 10;
		i++;
		copy_sint32power = copy_sint32power * 10;
	}
	sint32 int_num = copy_float64Float * 10000;
	copy_sint32power = copy_sint32power * 1000;
	while (copy_sint32power > 0) {								/*Sending floating point to LCD*/
		copy_uint32num = int_num / copy_sint32power;
		int_num %= copy_sint32power;
		copy_sint32power /= 10;
		if (i == 0) {
			LCD_voidSendData('.');
		}
		i--;
		LCD_voidSendData(copy_uint32num + '0');				/*sending number digit by digit to LCD as char*/
	}

}
