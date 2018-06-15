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
//#include "base.h"


/*
 * Second:
 * ------
 * Declare all variables that you will be using
 */

// First Challenge variable
//bool ForwardButton;
//int MaxSpeed;
//float LeftAdjust;
//float RightAdjust;

// Additional Second Challange variables
//bool ReverseButton
//bool LeftButton
//bool RightButton


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

		//ForwardButton = joystickGetDigital(1,7,JOY_UP);

		//MaxSpeed = 100; // Allowed values: -127 to 127
		//LeftAdjust = 1; // Allowed values 0 to 1
		//RightAdjust = 1; //Allowed valuers 0 to 1

		/*
		 * Fourth:
		 * ------
		 * Code robot operations
		 */

		// Challenge #1 - Driving Straight

		// Basic Method
		/*
		if(ForwardButton != 0){
			motorSet(10,100); // adjust second nunmber as needed for right wheels
			motorSet(1, -100); // adjust second number as needed for left wheels
			// -1 since motors turn in opposite directions
		}else{
			motorSet(1,0);
		  motorSet(10,0);
		}
		*/


		// More Advanced method
		/*
		if(ForwardButton != 0){
			motorSet(10,round(MaxSpeed * RightAdjust));
			motorSet(1, round(MaxSpeed * LeftAdjust * -1));
			// -1 since motors turn in opposite directions
		}else{
			motorSet(1,0);
		  motorSet(10,0);
		}
		*/

		// Challenge #2 - Labyrinth

		/*
		 * 1. Comment out Challenge #1 code above
		 * 2. Uncomment base.h inlcude
		 *    New Functions: BaseForward, BaseReverse, BaseLeft, BaseRight, BaseStop
		 * 3. Uncomment Challenge #2 variables.
		 * 4. Assign values to variables.
		 * 3. Code buttons and new functions to control robot.
		 * 		Hint: if(some_button){move_someway}else if(other_button){move_otherway}...}else{dont_move}
		 * 4. Each team member must navigate the Labyrinth with buttons.
		 */

		// Challenge #3 - Labyrinth II

		/*
		 * 1. Include base_joy.h
		 *    New Functions: LeftWheels, RightWheels
		 * 2. Declare additional variables:
		 *    LeftStickUpDown, RightStickUpDown
		 * 3. Assign variables to new joystick funtions
		 *		joystickGetAnalog({joystick #}, {joystick control #})
		 * 4. Extend code to inlcude analog joysticks.
		 *		New functions: BaseJoyLeft, BaseJoyRight
		 *    speed will be a dependant on max value and joystick value
		 *		Hint: Only check for analog sticks if no button is pushed.
		 * 5. Each team member must navigate the Labyrinth
		 *    (there is a twist though)
		 */

	}// end of while loop
} // end of operatorControl function
