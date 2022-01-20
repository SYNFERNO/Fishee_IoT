#ifndef FISHEE_SUHU_H
#define FISHEE_SUHU_H
#include <Arduino.h>
#include "Fishee_Setup.h"
#define ONE_WIRE_BUS D7

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

void init_suhu()
{
  sensors.begin();
}

float cek_suhu()
{
  sensors.requestTemperatures();
  float tempC = sensors.getTempCByIndex(0);
  
  if(tempC != DEVICE_DISCONNECTED_C) 
  {
    Serial.print("Temperature for the device 1 (index 0) is: ");
    Serial.println(tempC);
  } 
  else
  {
    Serial.println("Error: Could not read temperature data");
  }

  return tempC;
}

#endif
