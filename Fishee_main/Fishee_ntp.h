#ifndef FISHEE_NTP_H
#define FISHEE_NTP_H
#include <Arduino.h>
#include "Fishee_Setup.h"

const long utcOffsetInSeconds = 3600 * 7;
String daysOfTheWeek[7] = {"Minggu", "Senin ", "Selasa", "Rabu  ", "Kamis ", "Jum'at", "Sabtu "};
String months[12] = {"Januari", "Februari", "Maret", "April", "Mei", "Juni", "Juli", "Augustus", "September", "Oktober", "November", "Desember"};

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

  String formattedTime = timeClient.getFormattedTime();
  Serial.print("Formatted Time: ");
  Serial.println(formattedTime);
  return formattedTime;
}


#endif
