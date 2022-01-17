#ifndef FISHEE_SERVO_H
#define FISHEE_SERVO_H
#include <Arduino.h>
#include "Fishee_Setup.h"

Servo myservo;

int pos = 0;



void openfeeder() {
  myservo.attach(9);
  for (pos = 0; pos <= 180; pos += 1) {
    myservo.write(pos);
    delay(15);
  }
  for (pos = 180; pos >= 0; pos -= 1) {
    myservo.write(pos);
    delay(15);
  }
  feeder();
  delay(5555);
  unfeeder();
}

#endif
