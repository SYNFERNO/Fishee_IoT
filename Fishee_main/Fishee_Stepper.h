#ifndef FISHEE_STEPPER_H
#define FISHEE_STEPPER_H
#include <Arduino.h>
#include "Fishee_Setup.h"

const int stepsPerRevolution = 800;
const unsigned long MTBS = 1000;

Stepper myStepper(stepsPerRevolution, 5, 4, 18, 18);


void init_stepper()
{
  // set the speed at 60 rpm:
  myStepper.setSpeed(80);
}


void feeder()
{
  for (int i = 0; i <= 8; i++) {
    myStepper.setSpeed(60);
    myStepper.step(stepsPerRevolution);
  }
}

#endif
