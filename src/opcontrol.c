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

/*
 * First:
 * Add any needed header files.
 * Header files add functions that
 * can be used in the program.
 *
 * main.h = default robot and controller functions (required)
 * <math.h> = math functions such as round()
 * base.h = functions prewritten for summer camp base unit.
 *          needed for challange #2
 */

#include "main.h"
#include <math.h>
//#include "base.h"

/*
 * Runs the user operator control code. This function will be started in its own task with the
 * default priority and stack size whenever the robot is enabled via the Field Management System
 * or the VEX Competition Switch in the operator control mode. If the robot is disabled or
 * communications is lost, the operator control task will be stopped by the kernel. Re-enabling
 * the robot will restart the task, not resume it from where it left off.
 *
 * If no VEX Competition Switch or Field Management system is plugged in, the VEX Cortex will
 * run the operator control task. Be warned that this will also occur if the VEX Cortex is
 * tethered directly to a computer via the USB A to A cable without any VEX Joystick attached.
 *
 * Code running in this task can take almost any action, as the VEX Joystick is available and
 * the scheduler is operational. However, proper use of delay() or taskDelayUntil() is highly
 * recommended to give other tasks (including system tasks such as updating LCDs) time to run.
 *
 * This task should never exit; it should end with some kind of infinite loop, even if empty.
 */

/*
 * Second:
 * Declare all variables that you will be using
 */

//bool ForwardButton;
//int MaxSpeed;
//float LeftAdjust;
//float RightAdjust;


void operatorControl() { // Main function for controlling robot
	while (1) {

		/* Since while loop is set to true
		 * it will never never end.
		 * This is called an infinite loop.
		 * Usually a bad thing, but in this case
		 * allows program to remain running while
		 * robot is on.
		 */

		/*
		 * Third:
		 * Assign values or controller objects
		 * to variables declared above.
		 */

		//ForwardButton = joystickGetDigital(1,7,JOY_UP);
		//MaxSpeed = 100; // Allowed values: -127 to 127
		//LeftAdjust = 1; // Allowed values 0 to 1
		//RightAdjust = 1; //Allowed valuers 0 to 1

		/*
		 * Fourth:
		 * Code robot operations
		 */

		// Challenge #1 - Driving Straight

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
		 * 1. Remove Challenge #1 code above
		 * 2. Uncomment base.h
		 *    New Functions: BaseForward, BaseReverse, BaseLeft, BaseRight, BaseStop
		 * 3. Uncomment Challenge #2 variables.
		 * 4. Assign values to variables.
		 * 3. Code buttons and new functions to control robot.
		 * 4. Each team member must navigate the Labyrinth with buttons.
		 */

		// Challenge #3 - Labyrinth II

		/*
		 * 1. Include base_joy.h
		 * 2. Declare additional variables:
		 *    LeftStickUpDown, RightStickUpDown
		 * 3. Assign variables to new joystick funtions
		 *		joystickGetAnalog({joystick #}, {joystick control #})
		 * 4. Code joysticks.
		 *		New functions: BaseJoyLeft, BaseJoyRight
		 * 5. Each team member must navigate the Labyrinth
		 *    (there is a twist though)
		 */

	}// end of while loop
} // end of operatorControl function
