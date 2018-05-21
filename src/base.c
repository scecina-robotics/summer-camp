#include "api.h"

void BaseMotorSet(int motor_1, int motor_2){
  motorSet(1,motor_2);
  motorSet(10,motor_1);
}

void BaseForward(int speed){
  BaseMotorSet(speed,-speed);
}

void BaseReverse(int speed){
  BaseMotorSet(-speed,speed);
}

void BaseTurnRight(int speed){
  BaseMotorSet(speed,speed);
}

void BaseTurnLeft(int speed){
  BaseMotorSet(-speed,-speed);
}

void BaseStop(){
  BaseMotorSet(0,0);
}
