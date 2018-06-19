/** @file opcontrol.c
 * @brief File for operator control code
 *
 * This file should contain the user operatorControl() function and any functions related to it.
 *
 * Any copyright is dedicated to the Public Domain.
 * http://creativecommons.org/publicdomain/zero/1.0/
 *
 * PROS contains FreeRTOS (http://www.freertos.org) whose source code may be
 * obtained from http://sourceforge.net/projects/freertos/files/ or on request.
 */

// Single line comment

/*
 * Multiple line comment
 */

/*
 * First:
 * -----
 * Add any needed header files.
 * Header files add functions that
 * can be used in the program.
 *
 * main.h = default robot and controller functions (required)
 * <math.h> = math functions such as round()
 * base.h =
 *	- functions prewritten for summer camp base robot.
 *  - needed for challange #2 an #3
 */

#include "main.h"
#include <math.h>
#include "base.h"
#include "base_joy.h"


/*
 * Second:
 * ------
 * Declare all variables that you will be using
 */

// First Challenge variable
bool ForwardButton;

int MaxSpeed;
float LeftAdjust;
float RightAdjust;

// Additional Second Challange variables
bool ReverseButton;
bool LeftButton;
bool RightButton;

// Analog joystick
int LeftStickUpDown;
int RightStickUpDown;


void operatorControl() { // Main function for controlling robot
	while (1) {

		/* Note: Since while loop is set to
		 * true (1) it will never end.
		 * This is called an infinite loop.
		 * Usually a bad thing, but in this case
		 * allows program to remain running while
		 * robot is on.
		 */

		/*
		 * Third:
		 * -----
		 * Assign values or controller objects
		 * to variables declared above.
		 */

		ForwardButton = joystickGetDigital(1,7,JOY_UP);
		ReverseButton = joystickGetDigital(1,7,JOY_DOWN);
		LeftButton = joystickGetDigital(1, 7, JOY_LEFT);
		RightButton = joystickGetDigital(1, 7, JOY_RIGHT);

		LeftStickUpDown = joystickGetAnalog(1, 3);
		RightStickUpDown = joystickGetAnalog(1, 2);


		MaxSpeed = 100; // Allowed values: -127 to 127
		LeftAdjust = 1; // Allowed values 0 to 1
		RightAdjust = 1; //Allowed valuers 0 to 1

		/*
		 * Fourth:
		 * ------
		 * Code robot operations
		 */

		// Base Drive Code
		if(ForwardButton != 0){
		 BaseForward(MaxSpeed);
		}else if(ReverseButton != 0){
		 BaseReverse(MaxSpeed);
		}else if(LeftButton != 0){
		 BaseTurnLeft(MaxSpeed);
		}else if(RightButton != 0){
		 BaseTurnRight(MaxSpeed);
		}else{
		 LeftWheels(LeftStickUpDown);
		 RightWheels(RightStickUpDown);
		}


		// Challenge #1 - Button Stop/Start

		/*
		 * 1. Add a button toggle variable (bool)
		 * 2. Code if statements for BUTTON_SWITCH_!, BUTTON_SWITCH_2
		 * 	  condition = digitalRead(BUTTON_SWITCH_1) == LOW
		 *    use digitla ports 1 and 2
		 * 3. Code one button to stop robot control
		 *		and one button to start robot control
		 *		Hint: Nested if statement.
		 * 4. Include print statements to view button status on computer.
		 * 5. Play Tag.
		 */



		 // Challange #2 - Sonic Ranger

		 /*
		  * 1. Code the sonic ranger to stop forward progress
			*    if bot if something is within 10cm of an object
			* 2. Measuring Distance with sonic ranger
			*    int distance = ultrasonicGet(sonar);
			*/

	}// end of while loop
} // end of operatorControl function
