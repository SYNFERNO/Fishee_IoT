#ifndef FISHEE_STEPPER_H
#define FISHEE_STEPPER_H
#include <Arduino.h>
#include "Fishee_Setup.h"

#define MotorInterfaceType 4

const int stepsPerRevolution = 200;

Stepper myStepper(stepsPerRevolution, 5, 4, 14, 12); // D1, D2, D5, D6
AccelStepper stepper = AccelStepper(MotorInterfaceType, 5, 4, 14, 12);


void init_stepper()
{
  myStepper.setSpeed(10);
  stepper.setMaxSpeed(1000);
}

void feeder(int n)
{
  myStepper.setSpeed(n);
  myStepper.step(stepsPerRevolution);
}

void feeder2(int n)
{
  for (int i = 0; i < 50; i++) {
    // Set the speed of the motor in steps per second:
    stepper.setSpeed(n);
    // Step the motor with constant speed as set by setSpeed():
    stepper.runSpeed();
  }
}
#endif
