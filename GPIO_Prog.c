/*
 ===============================================================================================================
 Name        : GPIO_Prog.c
 Module Name : GPIO
 Author      : Ahmed Abd Elgleel
 Date        : 17 Aug 2023
 =================================================================================================================
 */

#include "GPIO_Private.h"
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GPIO_Interface.h"

/*---------------------------------------------- Setting Pin Direction ------------------------------------------*/

void GPIO_SetPinDirection(uint8 copy_uint8port, uint8 copy_uint8pin,uint8 copy_uint8direction)
{
	if (copy_uint8direction == INPUT) {
		switch (copy_uint8port) {
		case PORT_A:
			CLEAR_BIT(DDRA, copy_uint8pin);
			break;
		case PORT_B:
			CLEAR_BIT(DDRB, copy_uint8pin);
			break;
		case PORT_C:
			CLEAR_BIT(DDRC, copy_uint8pin);
			break;
		case PORT_D:
			CLEAR_BIT(DDRD, copy_uint8pin);
			break;
		}
	} else if (copy_uint8direction == OUTPUT) {
		switch (copy_uint8port) {
		case PORT_A:
			SET_BIT(DDRA, copy_uint8pin);
			break;
		case PORT_B:
			SET_BIT(DDRB, copy_uint8pin);
			break;
		case PORT_C:
			SET_BIT(DDRC, copy_uint8pin);
			break;
		case PORT_D:
			SET_BIT(DDRD, copy_uint8pin);
			break;
		}
	}
}

/*----------------------------------------------- Setting Pin Value -------------------------------------------------*/

void GPIO_SetPinValue(uint8 copy_uint8port, uint8 copy_uint8pin, uint8 copy_uint8value) {
	if (copy_uint8value == PIN_LOW) {
		switch (copy_uint8port) {
		case PORT_A:
			CLEAR_BIT(PORTA, copy_uint8pin);
			break;
		case PORT_B:
			CLEAR_BIT(PORTB, copy_uint8pin);
			break;
		case PORT_C:
			CLEAR_BIT(PORTC, copy_uint8pin);
			break;
		case PORT_D:
			CLEAR_BIT(PORTD, copy_uint8pin);
			break;
		}
	} else if (copy_uint8value == PIN_HIGH) {
		switch (copy_uint8port) {
		case PORT_A:
			SET_BIT(PORTA, copy_uint8pin);
			break;
		case PORT_B:
			SET_BIT(PORTB, copy_uint8pin);
			break;
		case PORT_C:
			SET_BIT(PORTC, copy_uint8pin);
			break;
		case PORT_D:
			SET_BIT(PORTD, copy_uint8pin);
			break;
		}
	}
}

/*---------------------------------------------------- Getting Pin Value --------------------------------------------------- */

void GPIO_GetPinValue(uint8 copy_uint8port, uint8 copy_uint8pin, uint8 *p_uint8_data) {
	switch (copy_uint8port) {
	case PORT_A:
		*p_uint8_data = GET_BIT(PINA, copy_uint8pin);
		break;
	case PORT_B:
		*p_uint8_data = GET_BIT(PINB, copy_uint8pin);
		break;
	case PORT_C:
		*p_uint8_data = GET_BIT(PINC, copy_uint8pin);
		break;
	case PORT_D:
		*p_uint8_data = GET_BIT(PIND, copy_uint8pin);
		break;
	}
}

/*----------------------------------------------------- Setting Port Direction ---------------------------------------------*/

void GPIO_SetPortDirection(uint8 copy_uint8port, uint8 copy_uint8direction) {
	if (copy_uint8direction == INPUT) {
		switch (copy_uint8port) {
		case PORT_A:
			DDRA = 0x00;
			break;
		case PORT_B:
			DDRB = 0x00;
			break;
		case PORT_C:
			DDRC = 0x00;
			break;
		case PORT_D:
			DDRD = 0x00;
			break;
		}
	} else if (copy_uint8direction == OUTPUT) {
		switch (copy_uint8port) {
		case PORT_A:
			DDRA = 0xFF;
			break;
		case PORT_B:
			DDRB = 0xFF;
			break;
		case PORT_C:
			DDRC = 0xFF;
			break;
		case PORT_D:
			DDRD = 0xFF;
			break;
		}
	}
}

/*------------------------------------------------- Setting Port Value ------------------------------------------------*/

void GPIO_SetPortValue(uint8 copy_uint8port, uint8 copy_uint8value) {
	switch (copy_uint8port) {
	case PORT_A:
		PORTA = copy_uint8value;
		break;
	case PORT_B:
		PORTB = copy_uint8value;
		break;
	case PORT_C:
		PORTC = copy_uint8value;
		break;
	case PORT_D:
		PORTD = copy_uint8value;
		break;
	}
}

/*----------------------------------------------- Getting Port Value -----------------------------------------------------*/

void GPIO_GetPortValue(uint8 copy_uint8port, uint8 *p_uint8_data) {
	switch (copy_uint8port) {
	case PORT_A:
		*p_uint8_data = PINA;
		break;
	case PORT_B:
		*p_uint8_data = PINB;
		break;
	case PORT_C:
		*p_uint8_data = PINC;
		break;
	case PORT_D:
		*p_uint8_data = PIND;
		break;
	}
}
