#ifndef FISHEE_HTTP_H
#define FISHEE_HTTP_H
#include <Arduino.h>
#include "Fishee_Setup.h"

// API KEY WEATHER
#define API_KEY "c7e63bcc8dc0bed68775e2e99c858db6"

const char *SERVER_IP = "http://3.81.3.232:8001/sensor";

String get_weather(String city) {
  WiFiClient clientt;
  HTTPClient http;

  http.begin(clientt, "http://api.openweathermap.org/data/2.5/weather?q=Indonesia&appid=c7e63bcc8dc0bed68775e2e99c858db6");

  Serial.print("[HTTP] GET...\n");

  int httpCode = http.GET();
  Serial.print(httpCode);
  String payload;
  
  if (httpCode > 0) {
    // HTTP header has been send and Server response header has been handled
    Serial.printf("[HTTP] GET... code: %d\n", httpCode);

    // file found at server
    if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) {
      payload = http.getString();
      Serial.println(payload);
    }
  }
  http.end();
  return payload;
}

void send_sensor(float ph, float suhu, int id, String nama, String tanggal) {
  WiFiClient clientt;
  HTTPClient http;

  Serial.print("[HTTP] begin...\n");
  http.begin(clientt, SERVER_IP); //HTTP
  http.addHeader("Content-Type", "application/plain");

  Serial.print("[HTTP] POST...\n");
  String data = "{\"deviceId\":\"1\",";
  data += "{\"suhu\":\"" + String(suhu) + "\",";
  data += "{\"ph\":\"" + String(ph) + "\",";
  data += "{\"ultraSonic\":\"" + String(suhu) + "\",";
  data += "{\"createBy\":\"" + String(id) + "\",";
  data += "{\"createByName\":\"" + nama + "\",";
  data += "{\"createAt\":\"" + tanggal + "\"}";
  int httpCode = http.POST(data);

  // httpCode will be negative on error
  if (httpCode > 0) {
    // HTTP header has been send and Server response header has been handled
    Serial.printf("[HTTP] POST... code: %d\n", httpCode);

    // file found at server
    if (httpCode == HTTP_CODE_OK) {
      const String& payload = http.getString();
      Serial.println("received payload:\n<<");
      Serial.println(payload);
      Serial.println(">>");
    }
  } else {
    Serial.printf("[HTTP] POST... failed, error: %s\n", http.errorToString(httpCode).c_str());
  }

  http.end();
}

#endif
