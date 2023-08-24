/*
 ==============================================================================================================================
 Name        : LCD_interface.h
 Author      : Ahmed Abd Elgleel
 Date        : 20 Aug 2023
 ===============================================================================================================================
 */
/* -----------------------------------------------------Function Prototypes of LCD----------------------------------------------*/

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

void LCD_voidSendCommand(uint8 copy_uint8Command);							/*Function used to Send Command to LCD*/

void LCD_voidSendData(uint8 copy_uint8Data);								/*Function used to Send Data to LCD*/

void LCD_Init(void);														/*Function used to set The Directions PINS Of LCD*/

void LCD_voidDisplayString(const uint8 *uint8_str);							/*Function used to Display String on LCD*/

void LCD_voidMoveCursor(uint8 copy_uint8Row, uint8 copy_uint8column);		/*Function Used to Move Cursor of LCD to certain position*/

void LCD_voidClearScreen(void);												/*Function used to Clear LCD Screen*/

void LCD_voiddisplayStringRowColumn(uint8 copy_uint8Row, uint8 copy_u8Column, const uint8 *Str);/*Function used to display string at certain pos*/

void LCD_voidSendNumber(sint32 copy_u3int2Number);							/*Function Used to Display Number on LCD*/

void LCD_voidSendFloat(float64 copy_float64Float);							/*Function use to display The floating operation on LCD*/

#endif /* LCD_INTERFACE_H_ */
/*-----------------------------------------------------------------------------------------------------------------------------*/
