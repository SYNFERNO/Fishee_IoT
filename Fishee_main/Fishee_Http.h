#ifndef FISHEE_HTTP_H
#define FISHEE_HTTP_H
#include <Arduino.h>
#include "Fishee_Setup.h"

// API KEY WEATHER
#define API_KEY "c7e63bcc8dc0bed68775e2e99c858db6"

String get_weather(String city) {
  WiFiClient clientt;
  HTTPClient http;

  http.begin(clientt, "http://api.weatherapi.com/v1/current.json?key=a399b860916f4e3698913135221202&q=" + city + "&aqi=no");

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

void send_sensor(String device, float suhu, float ph) {
  WiFiClient clientt;
  HTTPClient http;

  Serial.print("[HTTP] begin...\n");
  http.begin(clientt, "http://104.208.73.152/v1/Sensor"); //HTTP
  http.addHeader("Content-Type", "application/x-www-form-urlencoded");

  Serial.print("[HTTP] POST...\n");
  String httpRequestData = "device_id="+device+"&celcius="+String(suhu)+"&ph="+String(ph);
  
  int httpCode = http.POST(httpRequestData);

  // httpCode will be negative on error
  if (httpCode > 0) {
    // HTTP header has been send and Server response header has been handled
    Serial.printf("[HTTP] POST... code: %d\n", httpCode);
    Serial.printf("[HTTP] POST... failed, error: %s\n", http.errorToString(httpCode).c_str());

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

void send_feed(String device, float suhu, float ph) {
  WiFiClient clientt;
  HTTPClient http;

  Serial.print("[HTTP] begin...\n");
  http.begin(clientt, "http://104.208.73.152/v1/Feed"); //HTTP
  http.addHeader("Content-Type", "application/x-www-form-urlencoded");

  Serial.print("[HTTP] POST...\n");
  String httpRequestData = "device_id="+device+"&suhu="+String(suhu)+"&ph="+String(ph);
  
  int httpCode = http.POST(httpRequestData);

  // httpCode will be negative on error
  if (httpCode > 0) {
    // HTTP header has been send and Server response header has been handled
    Serial.printf("[HTTP] POST... code: %d\n", httpCode);
  Serial.printf("[HTTP] POST... failed, error: %s\n", http.errorToString(httpCode).c_str());

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
