#ifndef FISHEE_STEPPER_H
#define FISHEE_STEPPER_H
#include <Arduino.h>
#include "Fishee_Setup.h"

const int stepsPerRevolution = 800;
const unsigned long MTBS = 1000;

Stepper myStepper(stepsPerRevolution, 5, 4, 14, 12);


void init_stepper()
{
  // set the speed at 60 rpm:
  myStepper.setSpeed(80);
  // initialize the serial port:
  Serial.begin(9600);
}


void feeder()
{
  unsigned long lasttime;
  if (millis() - lasttime > MTBS)
  {
    myStepper.setSpeed(80);
    myStepper.step(stepsPerRevolution);

    lasttime = millis();
  }
}

void feederr()
{
  myStepper.setSpeed(80);
  myStepper.step(stepsPerRevolution);
}

void unfeeder()
{
  myStepper.step(0);
}

#endif
