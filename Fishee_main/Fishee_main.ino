#include "Fishee_Setup.h"

const unsigned long BOT_MTBS = 200; // mean time between scan messages
unsigned long bot_lasttime; // last time messages' scan has been done

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

    bot_lasttime = millis();
  }

  switch (WiFi.status()) {
    case WL_CONNECTED:
      digitalWrite(D4, HIGH);
      digitalWrite(D0, LOW);
      break;
    case WL_IDLE_STATUS:
      digitalWrite(D4, HIGH);
      delay(200);
      digitalWrite(D4, LOW);
      delay(200);
      break;
    case WL_CONNECT_FAILED:
      digitalWrite(D4, HIGH);
      digitalWrite(D0, HIGH);
      delay(200);
      digitalWrite(D4, LOW);
      digitalWrite(D0, LOW);
      delay(200);
      break;
    case WL_DISCONNECTED:
      digitalWrite(D4, HIGH);
      digitalWrite(D0, HIGH);
      delay(500);
      digitalWrite(D4, LOW);
      digitalWrite(D0, LOW);
      delay(500);
      break;
    case WL_CONNECTION_LOST:
      digitalWrite(D4, HIGH);
      digitalWrite(D0, HIGH);
      delay(300);
      digitalWrite(D4, LOW);
      digitalWrite(D0, LOW);
      delay(300);
      break;
  }
}
