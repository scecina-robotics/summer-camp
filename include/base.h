#ifndef _BASE_H_
#define _BASE_H_

void BaseMotorSet(int left_speed, int right_speed);

void BaseForward(int speed);
void BaseReverse(int speed);
void BaseTurnRight(int speed);
void BaseTurnLeft(int speed);

void BaseForwardAdjust(int left_speed, int right_speed);
void BaseReverseAdjust(int left_speed, int right_speed);

void BaseStop();

#endif
