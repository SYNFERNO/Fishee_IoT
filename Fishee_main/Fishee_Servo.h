#ifndef FISHEE_SERVO_H
#define FISHEE_SERVO_H
#include <Arduino.h>
#include "Fishee_Setup.h"

Servo myservo;

int pos = 0;

void init_servo() {
  myservo.attach(D3);
}

void openfeeder() {
  int pos;

  int(int i = 0; i <= 180; i++)
  {
    myservo.write(i);
    delay(15);
  }
  int(int i = 0; i <= 180; i--)
  {
    myservo.write(i);
    delay(15);
  }
}

#endif
