#include "api.h"

void LeftWheels(int speed){
  motorSet(1, -speed);
}

void RightWheels(int speed) {
  motorSet (10, speed);
}
