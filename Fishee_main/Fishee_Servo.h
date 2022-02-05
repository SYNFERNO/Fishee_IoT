#ifndef FISHEE_SERVO_H
#define FISHEE_SERVO_H
#include <Arduino.h>
#include "Fishee_Setup.h"

Servo myservo;

int pos = 0;

void openfeeder() {
  myservo.attach(D3);
  for (pos = 0; pos <= 360; pos += 1) {
    myservo.write(pos);
    delay(15);
    feederr();
  }
}

void closefeeder() {
  myservo.attach(D3);
  myservo.write(0);
  unfeeder();
}

#endif
