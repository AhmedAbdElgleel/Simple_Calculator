# Mini Project: ATmega32 Simple Calculator

This mini project implements a simple calculator using the ATmega32 microcontroller. The calculator can perform addition, subtraction, multiplication, and division operations. It utilizes drivers for GPIO, LCD, and a keypad for user input. The software development is done using Eclipse, and the simulation is performed in Proteus.

## Table of Contents

- [Introduction](#introduction)
- [Components Used](#components-used)
- [Functionality](#functionality)
- [Setup](#setup)
- [Usage](#usage)
- [Code Comments](#code-comments)
- [Simulation](#simulation)
- [Future Improvements](#future-improvements)
- [License](#license)

## Introduction

The ATmega32 Simple Calculator is a basic calculator application that runs on an ATmega32 microcontroller. It can handle four arithmetic operations: addition, subtraction, multiplication, and division. The calculator takes user input through a keypad, displays the input and results on an LCD screen, and provides an output based on the selected operation.

## Components Used

- ATmega32 Microcontroller
- GPIO (General Purpose Input/Output) Driver
- LCD (Liquid Crystal Display) Driver
- Keypad Driver
- Keypad
- Breadboard and Jump Wires

## Functionality

The calculator provides the following functionality:

1. **User Input**: Users can enter numbers and select arithmetic operations using the keypad.
2. **Arithmetic Operations**: The calculator supports addition, subtraction, multiplication, and division.
3. **Display**: User input and calculation results are displayed on the LCD.
4. **Clear**: Users can clear the input and start a new calculation.

## Setup

To set up the project, follow these steps:

1. Connect the ATmega32 microcontroller to the power supply, LCD, and keypad.
2. Configure the GPIO, LCD, and keypad drivers to interact with the hardware.
3. Develop the source code using Eclipse.
4. Load the compiled code onto the microcontroller.
5. Ensure all connections are correct and secure.
6. Power on the microcontroller.

## Usage

1. The LCD screen will display the current input or result.
2. Use the keypad to input numbers and select arithmetic operations.
3. Press the appropriate operation key (+, -, *, /) to perform the desired calculation.
4. The result will be displayed on the LCD screen.
5. To start a new calculation, press the clear key.

## Code Comments

The source code is developed using Eclipse and is heavily commented to enhance understanding. Each line of code that may require explanation or clarification has a corresponding comment explaining its purpose or functionality.


## Simulation

The functionality of the ATmega32 Simple Calculator can be simulated using Proteus. The Proteus simulation file is provided with the project. Follow these steps:

1. Open the Proteus simulation file in Proteus software.
2. Run the simulation to observe how the calculator interacts with the keypad and LCD.

## Future Improvements

Here are some ideas for future improvements:

1. **Decimal Support**: Enhance the calculator to handle decimal numbers and floating-point arithmetic.
2. **Memory Functions**: Implement memory storage and retrieval functions.
3. **Advanced Operations**: Add support for more advanced operations like square root, exponentiation, etc.
4. **User Interface**: Design a more user-friendly interface on the LCD for better user experience.


Feel free to modify and expand upon this readme template according to your project's specific details and requirements. Good luck with your ATmega32 Simple Calculator project using Eclipse and Proteus!
