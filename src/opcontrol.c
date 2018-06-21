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

// Additional Second Challange variables
bool ReverseButton;
bool LeftButton;
bool RightButton;

// Analog joystick
int LeftStickUpDown;
int RightStickUpDown;

// Button Switch Toggle
bool ButtonSwitch;

// Sonic Ranger
int Distance;
int AutoDistance;
int StopDistance;

// Automation
bool AutoOn;


// Turning Times
int Time90;
int TimeReverse;
int TimePause;

void operatorControl() { // Main function for controlling robot
	// We need to preset the ButtonSwitch before starting loop
	ButtonSwitch = true;
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


		MaxSpeed = 125; // Allowed values: -127 to 127

		Distance = ultrasonicGet(sonar);
		StopDistance = 10;

		// Automation Switch
		// AutoOn = joystickGetDigital(1,6,JOY_UP);
		AutoOn = 0;

		// Times
		Time90 = 2000;
		TimeReverse = 1000;
		TimePause = 1000;

		/*
		 * Fourth:
		 * ------
		 * Code robot operations
		 */

		// Challenge #4 - Automation Challenge

		/* Take data for power vs. ft/s graph.
		 * Take data for time vs. angle at power = 50.
		 * Assign values to S-[1-4] and T-[1-3]
		 * to complete maze.
		 */


  if(ButtonSwitch){
      //if(ForwardButton != 0 && Distance > StopDistance){
			if(ForwardButton != 0){	//Disable Sonic Ranger
				BaseForward(MaxSpeed);
			}else if(ReverseButton != 0){
			 BaseReverse(MaxSpeed);
			}else if(LeftButton != 0){
			 BaseTurnLeft(MaxSpeed);
			}else if(RightButton != 0){
			 BaseTurnRight(MaxSpeed);
		  }else if(AutoOn != 0){
			  //DAY 4: Automation Challenge
				// S-1
				BaseStop();
				BaseForward(100); // Power (0-127)
		 		delay(1000); // Time (mS)
				// T-1
				BaseStop();
				delay(TimePause);
				BaseTurnLeft(50);
				delay(1000); // Time (ms)
				// S-2
				BaseStop();
				delay(TimePause);
				BaseForward(100); //Power (0-127)
		 		delay(1000); // Time (mS)
				// T-2
				BaseStop();
				delay(TimePause);
				BaseTurnRight(50);
				delay(1000); // Time (ms)
				// S-3
				BaseStop();
				delay(TimePause);
				BaseForward(100); //Power (0-127)
		 		delay(1000); // Time (mS)
				// T-3
				BaseStop();
				delay(TimePause);
				BaseTurnRight(50);
				delay(1000); // Time (ms)
				// S-4
				BaseStop();
				delay(TimePause);
				BaseForward(100); //Power (0-127)
		 		delay(1000); // Time (mS)
			}else{
			 LeftWheels(LeftStickUpDown);
			 RightWheels(RightStickUpDown);
			}
	  }else{
			BaseStop();
		}


		 if (digitalRead(BUTTON_SWITCH_1) == LOW ){
			 ButtonSwitch = false;
			 print("Button 1 Pushed");
		 }

		 if (digitalRead(BUTTON_SWITCH_2) == LOW){
			 ButtonSwitch = true;
			 print("Button 2 Pushed");
		 }




	}// end of while loop
} // end of operatorControl function
