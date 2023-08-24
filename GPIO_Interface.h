/*
 ============================================================================
 Name        : GPIO_Interface.h
 Module Name : GPIO
 Author      : Ahmed Abd Elgleel
 Date        : 17 Aug 2023
 ============================================================================
 */
#include "STD_TYPES.h"

#ifndef GPIO_INTERFACE_H_
#define GPIO_INTERFACE_H_

typedef enum {
	PORT_A, PORT_B, PORT_C, PORT_D
} et_port;

typedef enum {
	PIN0, PIN1, PIN2, PIN3, PIN4, PIN5, PIN6, PIN7
} et_pin;

typedef enum {
	INPUT, OUTPUT
} et_direction;

typedef enum {
	PIN_LOW, PIN_HIGH
} et_Status;


void GPIO_SetPinDirection(uint8 copy_uint8port, uint8 copy_uint8pin,uint8 copy_uint8direction);		/* Setting Pin Direction input or output */


void GPIO_SetPinValue(uint8 copy_uint8port, uint8 copy_uint8pin, uint8 copy_uint8value);			/* Setting Pin Value */


void GPIO_GetPinValue(uint8 uint8_port, uint8 uint8_pin, uint8 *p_uint8_data);						/* Getting Pin Value */


void GPIO_SetPortDirection(uint8 uint8_port, uint8 uint8_direction);								/* Setting Port Direction */


void GPIO_SetPortValue(uint8 uint8_port, uint8 uint8_value);										/* Setting Port Value */


void GPIO_GetPortValue(uint8 uint8_port, uint8 *p_uint8_data);										/* Getting Port Value */

#endif /* GPIO_INTERFACE_H_ */
