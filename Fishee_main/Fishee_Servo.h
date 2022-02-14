#ifndef FISHEE_SERVO_H
#define FISHEE_SERVO_H
#include <Arduino.h>
#include "Fishee_Setup.h"

Servo myservo;

void init_servo() {
  myservo.attach(D3);
   myservo.write(0);
}

void openfeeder() {
  int pos = 0;
  for( pos = 0; pos <= 180; pos++)
  {
    myservo.write(pos);
    delay(15);
  }
  for( pos = 0; pos <= 180; pos--)
  {
    myservo.write(pos);
    delay(15);
  }
  for( pos = 0; pos <= 180; pos++)
  {
    myservo.write(pos);
    delay(15);
  }
  for( pos = 0; pos <= 180; pos--)
  {
    myservo.write(pos);
    delay(15);
  }
  Serial.println("wes tekan");
}

#endif
