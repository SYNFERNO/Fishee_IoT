#ifndef FISHEE_STEPPER_H
#define FISHEE_STEPPER_H
#include <Arduino.h>
#include "Fishee_Setup.h"

const int stepsPerRevolution = 800;

Stepper myStepper(stepsPerRevolution, 5, 4, 14, 12); // D1, D2, D5, D6



void init_stepper()
{
  // set the speed at 60 rpm:
  myStepper.setSpeed(80);
}


void feeder()
{
  for (int i = 0; i <= 25; i++) {
    myStepper.step(stepsPerRevolution);
  }
}

#endif
