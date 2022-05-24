#ifndef FISHEE_TELE_H
#define FISHEE_TELE_H
#include <Arduino.h>
#include "Fishee_Setup.h"

// Telegram BOT Token (Get from Botfather)
#define BOT_TOKEN "5005722661:AAFb0ynziDY8_oEE4jjfMPNfuk6blt4u5-Q"

int stepperSpeed = 60;

UniversalTelegramBot bot(BOT_TOKEN, secured_client);

int state = 0;

void handleNewMessages(int numNewMessages)
{
  Serial.print("handleNewMessages ");
  Serial.println(numNewMessages);

  String answer;
  for (int i = 0; i < numNewMessages; i++)
  {
    telegramMessage &msg = bot.messages[i];
    Serial.println("Received " + msg.text);
    if (msg.text == "/start")
    {
      answer = "Hello " + msg.from_name + ", Welcome to the fishee butler bot!!!\n\n";
      answer += "I can help you monitor your fish pond and manage Telegram bots.\n";
      answer += "You can control me by sending these commands: \n\n";
      answer += "/status - check the status of your fish pond.\n";
      answer += "/feed - feed your fish\n";
      answer += "/wheater - check current weather status\n";
      answer += "/help - bot command list\n";
    }
    else if (msg.text == "/help") {
      answer = "I can help you monitor your fish pond and manage Telegram bots.\n";
      answer += "You can control me by sending these commands: \n\n";
      answer += "/status - check the status of your fish pond.\n";
      answer += "/feed - feed your fish\n";
      answer += "/wheater - check current weather status\n";
      answer += "/help - bot command list\n";
    }
    else if (msg.text == "/status")
    {
      float a = cek_suhu();
      float b = phMeter();
      send_sensor("1", a, b);
      answer = "Current water temperature : " + String(a, 2) + "°C\n";
      answer += "current pH : " + String(b, 2) + "\n";
    }
    else if (msg.text == "/feed")
    {
      String keyboardJson = "[[\"10\", \"20\"],[\"30\", \"40\"],[\"50\", \"60\"],[\"70\", \"80\"],[\"90\", \"100\"]]";
      bot.sendMessageWithReplyKeyboard(msg.chat_id, "Choose from one of the following speed", "", keyboardJson, true);
    }
    else if (msg.text == "10")
    {
      stepperSpeed = msg.text.toInt();
      
      String aa = "Start feeding the fish using speed " + msg.text;
      
      bot.sendMessage(msg.chat_id, aa, "Markdown");
      state = 1;
      //feeder(n);
      //feeder2(500);
      float a = cek_suhu();
      float b = phMeter();
      send_feed("1", a, b);
    }
    else if (msg.text == "20")
    {
      stepperSpeed = msg.text.toInt();
      
      String aa = "Start feeding the fish using speed " + msg.text;
      
      bot.sendMessage(msg.chat_id, aa, "Markdown");
      state = 1;
      //feeder(n);
      //feeder2(500);
      float a = cek_suhu();
      float b = phMeter();
      send_feed("1", a, b);
    }
    else if (msg.text == "30")
    {
      stepperSpeed = msg.text.toInt();
      
      String aa = "Start feeding the fish using speed " + msg.text;
      
      bot.sendMessage(msg.chat_id, aa, "Markdown");
      state = 1;
      //feeder(n);
      //feeder2(500);
      float a = cek_suhu();
      float b = phMeter();
      send_feed("1", a, b);
    }
    else if (msg.text == "40")
    {
      stepperSpeed = msg.text.toInt();
      
      String aa = "Start feeding the fish using speed " + msg.text;
      
      bot.sendMessage(msg.chat_id, aa, "Markdown");
      state = 1;
      //feeder(n);
      //feeder2(500);
      float a = cek_suhu();
      float b = phMeter();
      send_feed("1", a, b);
    }
    else if (msg.text == "50")
    {
      stepperSpeed = msg.text.toInt();
      
      String aa = "Start feeding the fish using speed " + msg.text;
      
      bot.sendMessage(msg.chat_id, aa, "Markdown");
      state = 1;
      //feeder(n);
      //feeder2(500);
      float a = cek_suhu();
      float b = phMeter();
      send_feed("1", a, b);
    }
    else if (msg.text == "60")
    {
      stepperSpeed = msg.text.toInt();
      
      String aa = "Start feeding the fish using speed " + msg.text;
      
      bot.sendMessage(msg.chat_id, aa, "Markdown");
      state = 1;
      //feeder(n);
      //feeder2(500);
      float a = cek_suhu();
      float b = phMeter();
      send_feed("1", a, b);
    }
    else if (msg.text == "70")
    {
      stepperSpeed = msg.text.toInt();
      
      String aa = "Start feeding the fish using speed " + msg.text;
      
      bot.sendMessage(msg.chat_id, aa, "Markdown");
      state = 1;
      //feeder(n);
      //feeder2(500);
      float a = cek_suhu();
      float b = phMeter();
      send_feed("1", a, b);
    }
    else if (msg.text == "80")
    {
      stepperSpeed = msg.text.toInt();
      
      String aa = "Start feeding the fish using speed " + msg.text;
      
      bot.sendMessage(msg.chat_id, aa, "Markdown");
      state = 1;
      //feeder(n);
      //feeder2(500);
      float a = cek_suhu();
      float b = phMeter();
      send_feed("1", a, b);
    }
    else if (msg.text == "90")
    {
      stepperSpeed = msg.text.toInt();
      
      String aa = "Start feeding the fish using speed " + msg.text;
      
      bot.sendMessage(msg.chat_id, aa, "Markdown");
      state = 1;
      //feeder(n);
      //feeder2(500);
      float a = cek_suhu();
      float b = phMeter();
      send_feed("1", a, b);
    }
    else if (msg.text == "100")
    {
      stepperSpeed = msg.text.toInt();
      
      String aa = "Start feeding the fish using speed " + msg.text;
      
      bot.sendMessage(msg.chat_id, aa, "Markdown");
      state = 1;
      //feeder(n);
      //feeder2(500);
      float a = cek_suhu();
      float b = phMeter();
      send_feed("1", a, b);
    }
    else if (msg.text == "/wheater")
    {
      String country = "Malaysia";
      String payload = get_weather(country);
      DynamicJsonDocument doc(2048);
      deserializeJson(doc, payload);

      answer = "weather forecast " + country;
      answer += doc["location"]["localtime"].as<String>() + "\n\n";
      answer += "Suhu Celsius : " + doc["current"]["temp_c"].as<String>() + "\n";
      answer += "Suhu Fanreheit : " + doc["current"]["temp_f"].as<String>() + "\n";
      answer += "Kelembapan : " + doc["current"]["humidity"].as<String>() + "\n";
      answer += "Kondisi : " + doc["current"]["condition"]["text"].as<String>() + "\n";
      answer += "Angin : " + doc["current"]["wind_mph"].as<String>() + "mph, " + doc["current"]["wind_kph"].as<String>() + "kph\n";
    }
    else
      answer = "Please use command. or type /help to see command bot list";

    bot.sendMessage(msg.chat_id, answer, "Markdown");
  }
}

void bot_setup()
{
  const String commands = F("["
                            "{\"command\":\"start\"},"
                            "{\"command\":\"help\",  \"description\":\"bot command list\"},"
                            "{\"command\":\"status\",\"description\":\"check the status of your fish pond\"},"
                            "{\"command\":\"feed\", \"description\":\"feed your fish\"},"
                            "{\"command\":\"wheater\", \"description\":\"check current weather status\"}"
                            "]");
  bot.setMyCommands(commands);
}

#endif
