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

// Button Switch Toggle
bool ButtonSwitch;

// DAY 3 - Variables
// Button to turn on automation
bool AutoOn;
// Button to turn off automation
bool AutoOff;
// Toggle for automation
bool AutoToggle;
// Variable for Automation Turn Speed
int TurnSpeed;
int AutoSpeed;
// Variables for robot to turn
int Time45;
int Time90;
int Time135;
int Time180;
// Variable for time to backup
int TimeBack;
int TimePause;
// Variable for Distance to stop.
int Distance;
int StopDistance;

void operatorControl() { // Main function for controlling robot
	// We need to preset the ButtonSwitch before starting loop
	ButtonSwitch = true;
	AutoToggle = false;
	// Use current time as seed for random generator
	while (1) {

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

		// DAY 3 - Variable assignment:
		//Auto Buttons
		AutoOn = joystickGetDigital(1, 6, JOY_UP);
		AutoOff = joystickGetDigital(1, 6, JOY_DOWN);
		// Speeds
		TurnSpeed = 50;
		AutoSpeed = 50;
		// Variables for robot to turn
		Time45 = 100;
		Time90 = 200;
		Time135 = 300;
		Time180 = 400;
		// Variable for time to backup
		TimeBack = 100;
		TimePause = 50;
		// Variable for Distance and stop.
		Distance = ultrasonicGet(sonar);
		StopDistance = 10;

		/*
		 * Fourth:
		 * ------
		 * Code robot operations
		 */

		 // DAY 3 Code:

		 //Toggle Automation
		 /*
		 if(AutoOn != 0){
			 AutoToggle = true;
			 print("Auto Toggle On");
		 }
		 if(AutoOff != 0){
			 AutoToggle = false;
			 print("Auto Toggle Off");
		 */
/*
		 // Automation
		 while(AutoToggle){
			 if(Distance > StopDistance){
				 BaseForward(AutoSpeed);
			 }else{
				 BaseStop();
				 BaseReverse(AutoSpeed);
				 delay(TimeBack);
				 BaseStop();
				 delay(TimePause);
				 switch (rand() % 7) {
				 	case 0:
						BaseTurnLeft(AutoSpeed);
						delay(Time45);
						break;
					case 1:
						BaseTurnLeft(AutoSpeed);
						delay(Time90);
						break;
					case 2:
						BaseTurnLeft(AutoSpeed);
						delay(Time135);
						break;
					case 3:
						BaseTurnLeft(AutoSpeed);
						delay(Time180);
						break;
					case 4:
						BaseTurnRight(AutoSpeed);
						delay(Time135);
						break;
					case 5:
						BaseTurnRight(AutoSpeed);
						delay(Time90);
						break;
					case 6:
						BaseTurnRight(AutoSpeed);
						delay(Time45);
						break;
					default:
						BaseStop();
				 }
				 BaseStop();
				 delay(TimePause);
				 BaseForward(AutoSpeed);
			 }
			 if(AutoOff != 0){
				 AutoToggle = false;
				 print("Auto Toggle Off");
			 }
		 }
*/
		 //
		//Disable control is stop button pushed or automation in progress

			if(ButtonSwitch){
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
		  }else{
				BaseStop();
			}
			// Button Controls
			if (digitalRead(BUTTON_SWITCH_1) == LOW ){
			 ButtonSwitch = false;
				print("Button 1 Pushed");
			 }
			 if (digitalRead(BUTTON_SWITCH_2) == LOW){
				 ButtonSwitch = true;
				 print("Button 2 Pushed");
			 }


		 // Challange #2 - Sonic Ranger

		 /*
		  * 1. Code the sonic ranger to stop forward progress
			*    if bot if something is within 10cm of an object
			* 2. Measuring Distance with sonic ranger
			*    int distance = ultrasonicGet(sonar);
			*/


	}// end of while loop
} // end of operatorControl function
