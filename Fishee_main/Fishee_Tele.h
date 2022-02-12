#ifndef FISHEE_TELE_H
#define FISHEE_TELE_H
#include <Arduino.h>
#include "Fishee_Setup.h"

// Telegram BOT Token (Get from Botfather)
#define BOT_TOKEN "5005722661:AAFb0ynziDY8_oEE4jjfMPNfuk6blt4u5-Q"

UniversalTelegramBot bot(BOT_TOKEN, secured_client);

void handleNewMessages(int numNewMessages)
{
  Serial.print("handleNewMessages ");
  Serial.println(numNewMessages);

  String answer;
  for (int i = 0; i < numNewMessages; i++)
  {
    telegramMessage &msg = bot.messages[i];
    Serial.println("Received " + msg.text);
    if (msg.text == "/help") {
      answer = "This is all feature we have.\n";
      answer += "/help : Fishee bot siap membantu!\n";
      answer += "/start : Selamat datang di Fishee bot!\n";
      answer += "/status : Informasi status pada setiap sensor\n";
      answer += "/feed : Saatnya memberi pakan ikan\n";
      answer += "/wheater : Perkiraan cuaca Senin, 10 Februari 2022\n";
    }
    else if (msg.text == "/start")
    {
      answer = "Selamat datang di Fishee bot!\n";
      answer += "You, " + msg.from_name + ", thank for choosing fishee.\n";
      answer += "/help : show all feature of fishee\n";
    }
    else if (msg.text == "/status")
    {
      float a = cek_suhu();
      float b = phMeter();
      answer = "Suhu Air : " + String(a, 2) + "\n";
      answer += "Ph Air : " + String(b, 2) + "\n";
    }
    else if (msg.text == "/feed")
    {
//      const char aa = "Saatnya memberi pakan ikan!";
//      bot.sendMessage(msg.chat_id, aa, "Markdown");
      feeder();
      yield();
      answer = "Beri pakan ikan selesai!";
    }
    else if (msg.text == "/wheater")
    {
      String payload = get_weather("Yogyakarta");
      DynamicJsonDocument doc(2048);
      deserializeJson(doc, payload);
      
      answer = "Perkiraan cuaca ";
      answer += doc["location"]["localtime"].as<String>() + "\n\n";
      answer += "Suhu Celsius : " + doc["current"]["temp_c"].as<String>() + "\n";
      answer += "Suhu Fanreheit : " + doc["current"]["temp_f"].as<String>() + "\n";
      answer += "Kelembapan : " + doc["current"]["humidity"].as<String>() + "\n";
      answer += "Kondisi : " + doc["current"]["condition"]["text"].as<String>() + "\n";
      answer += "Angin : " + doc["current"]["wind_mph"].as<String>() + "mph, " + doc["current"]["wind_kph"].as<String>() + "kph\n";
      
      Serial.println(doc["weather"].as<String>());
      
      send_sensor(1,2,1,"ss","dd");
    }
    else
      answer = "Please use command.";

    bot.sendMessage(msg.chat_id, answer, "Markdown");
  }
}

void bot_setup()
{
  const String commands = F("["
                            "{\"command\":\"help\",  \"description\":\"Fishee bot siap membantu!\"},"
                            "{\"command\":\"start\", \"description\":\"Selamat datang di Fishee bot!\"},"
                            "{\"command\":\"status\",\"description\":\"Informasi status pada setiap sensor\"},"
                            "{\"command\":\"feed\", \"description\":\"Saatnya memberi pakan ikan\"},"
                            "{\"command\":\"wheater\", \"description\":\"Perkiraan cuaca Senin, 10 Februari 2022\"}"
                            "]");
  bot.setMyCommands(commands);
}

#endif
