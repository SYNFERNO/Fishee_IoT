#ifndef FISHEE_NTP_H
#define FISHEE_NTP_H
#include <Arduino.h>
#include "Fishee_Setup.h"

const long utcOffsetInSeconds = 3600 * 7;
char daysOfTheWeek[7][12] = {"Minggu", "Senin ", "Selasa", "Rabu  ", "Kamis ", "Jum'at", "Sabtu "};

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org", utcOffsetInSeconds);

void init_time() {
  timeClient.begin();
}

String get_time() {
  timeClient.update();
  Serial.print("Hari: "); Serial.println(daysOfTheWeek[timeClient.getDay()]);
  Serial.print("Jam: "); Serial.println(timeClient.getHours());
  Serial.print("Menit: "); Serial.println(timeClient.getMinutes());
  Serial.print("Detik: "); Serial.println(timeClient.getSeconds());
  Serial.println();
  Serial.print(daysOfTheWeek[timeClient.getDay()]);
  Serial.print(",");
  Serial.println(timeClient.getFormattedTime());

  String a = daysOfTheWeek[timeClient.getDay()] + ", ";
  a += timeClient.getHours() + ":";
  a += timeClient.getMinutes();
  return
}


#endif