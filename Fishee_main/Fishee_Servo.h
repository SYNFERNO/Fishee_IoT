#ifndef FISHEE_SERVO_H
#define FISHEE_SERVO_H
#include <Arduino.h>
#include "Fishee_Setup.h"

Servo myservo;

int pos = 0;

void init_servo(){
  myservo.attach(D3);
}

void openfeeder() {
 myservo.write(10);
 delay(50);
 myservo.write(360);
 delay(50);
 myservo.write(10);
 delay(50);
 myservo.write(360);
 delay(50);
 myservo.write(10);
 delay(50);
 myservo.write(360);
 delay(50);
}

#endif
