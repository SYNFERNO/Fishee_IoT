#ifndef FISHEE_STEPPER_H
#define FISHEE_STEPPER_H
#include <Arduino.h>
#include "Fishee_Setup.h"

const int stepsPerRevolution = 800;

Stepper myStepper(stepsPerRevolution, 14, 12, 13, 15);


void init_stepper()
{
  // set the speed at 60 rpm:
  myStepper.setSpeed(80);
  // initialize the serial port:
  Serial.begin(9600);
}

void test_stepper() 
{
  // step one revolution in one direction:
  Serial.println("clockwise");
  myStepper.step(stepsPerRevolution);
  delay(500);

  // step one revolution in the other direction:
  Serial.println("counterclockwise");
  myStepper.step(-stepsPerRevolution);
  delay(500);
}

void feeder()
{
  Serial.println("Waktu Beri Makan");
  myStepper.setSpeed(80);
  myStepper.step(stepsPerRevolution);
}

void unfeeder()
{
  myStepper.step(0);
}

#endif
