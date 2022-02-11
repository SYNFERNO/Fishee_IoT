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
  Serial.println("test servo");
  myservo.write(-180);
  delay(100);
  myservo.write(180);
  delay(100);
}

#endif
