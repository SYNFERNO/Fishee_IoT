#include "Fishee_Setup.h"

const unsigned long BOT_MTBS = 200; // mean time between scan messages

const unsigned long Wifi_status1 = 100; // mean time between scan messages
const unsigned long Wifi_status2 = 200; // mean time between scan messages
const unsigned long Wifi_status3 = 300; // mean time between scan messages
const unsigned long Wifi_status4 = 400; // mean time between scan messages
const unsigned long Wifi_status5 = 500; // mean time between scan messages
const unsigned long Wifi_status6 = 600; // mean time between scan messages

unsigned long bot_lasttime; // last time messages' scan has been done
unsigned long wifi_lasttime; // last time messages' scan has been done
unsigned long status_lasttime; // last time messages' scan has been done

int count = 0;

void setup()
{
  Serial.begin(115200);


  pinMode(D7, OUTPUT);
  pinMode(D6, OUTPUT);
  pinMode(D5, OUTPUT);
  pinMode(D4, OUTPUT);
  pinMode(D3, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(D1, OUTPUT);
  pinMode(D0, OUTPUT);

  digitalWrite(D0, LOW);
  digitalWrite(D3, HIGH);
  digitalWrite(D4, LOW);


  init_wifi();
  init_suhu();
  bot_setup();
  init_stepper;
}

void loop()
{
  unsigned long currentMillis = millis();

  if (wm_nonblocking) wm.process();
  if (millis() - bot_lasttime > BOT_MTBS)
  {
    int numNewMessages = bot.getUpdates(bot.last_message_received + 1);

    while (numNewMessages)
    {
      Serial.println("got response");
      handleNewMessages(numNewMessages);
      numNewMessages = bot.getUpdates(bot.last_message_received + 1);
    }

    bot_lasttime = currentMillis;
  }

  if (millis() - status_lasttime > 300000)
  {
    float a = cek_suhu();
    float b = phMeter();
    send_sensor("1", a, b);
    status_lasttime = currentMillis;
  }

  if (millis() - status_lasttime > 300000)
  {
    float a = cek_suhu();
    float b = phMeter();
    send_sensor("1", a, b);
    status_lasttime = currentMillis;
  }

  if (millis() - status_lasttime > 60000)
  {
    float a = cek_suhu();
    float b = phMeter();

    if ((a < 25 || a > 30) || (b < 6, 5 || b > 8)) {

      digitalWrite(D4, HIGH);
      delay(300);
      digitalWrite(D4, LOW);
    }
    status_lasttime = currentMillis;
  }

  switch (WiFi.status()) {
    case WL_CONNECTED:
      digitalWrite(D4, HIGH);
      digitalWrite(D0, LOW);

      wifi_lasttime = currentMillis;
      break;
    case WL_IDLE_STATUS:
      if (millis() - wifi_lasttime > Wifi_status1) {
        digitalWrite(D4, HIGH);
      }

      if (millis() - wifi_lasttime > Wifi_status6) {
        digitalWrite(D4, LOW);
      }

      wifi_lasttime = currentMillis;
      break;
    case WL_CONNECT_FAILED:
      if (millis() - wifi_lasttime > Wifi_status1) {
        digitalWrite(D4, HIGH);
        digitalWrite(D0, HIGH);
      }

      if (millis() - wifi_lasttime > Wifi_status3) {
        digitalWrite(D4, LOW);
        digitalWrite(D0, LOW);
      }

      wifi_lasttime = currentMillis;
      break;
    case WL_DISCONNECTED:
      if (millis() - wifi_lasttime > Wifi_status1) {
        digitalWrite(D4, HIGH);
        digitalWrite(D0, HIGH);
      }

      if (millis() - wifi_lasttime > Wifi_status4) {
        digitalWrite(D4, LOW);
        digitalWrite(D0, LOW);
      }

      wifi_lasttime = currentMillis;
      break;
    case WL_CONNECTION_LOST:
      if (millis() - wifi_lasttime > Wifi_status1) {
        digitalWrite(D4, HIGH);
        digitalWrite(D0, HIGH);
      }

      if (millis() - wifi_lasttime > Wifi_status3) {
        digitalWrite(D4, LOW);
        digitalWrite(D0, LOW);
      }

      wifi_lasttime = currentMillis;
      break;
  }

  switch (state) {
    case 1:
      //digitalWrite(D3, LOW);
      if (count < 1000) {
        feeder(stepperSpeed);
        count++;
        delay(20);
      }
      count = 0;
      state = 0;
      break;
    case 0:
      break;
  }
}
