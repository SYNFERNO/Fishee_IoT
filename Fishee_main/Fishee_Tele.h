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
      answer += "/help : show all feature of fishee\n";
      answer += "/status : show water tempterature and water Ph\n";
      answer += "/feed : feed your fish\n";
      answer += "/last : show last time you give feed\n";
    }
    else if (msg.text == "/start")
    {
      answer = "Welcome to Fishee Butler.\n";
      answer += "Fishe is blablablabla.\n\n";
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
      openfeeder();
      answer = "Beri makan ikan dimulai!";
    } else if (msg.text == "/last")
    {
      answer = "Terakhir beri makan : ";
    }
    else
      answer = "Please use command.";

    bot.sendMessage(msg.chat_id, answer, "Markdown");
  }
}

void bot_setup()
{
  const String commands = F("["
                            "{\"command\":\"help\",  \"description\":\"Get bot usage help\"},"
                            "{\"command\":\"start\", \"description\":\"Selamat datang di Fishee Bot\"},"
                            "{\"command\":\"status\",\"description\":\"Dapatkan Status pada setiap sensor\"},"
                            "{\"command\":\"feed\", \"description\":\"Beri makanan ikans\"},"
                            "{\"command\":\"unfeed\", \"description\":\"Beri makanan selesai\"}"
                            "]");
  bot.setMyCommands(commands);
}

#endif
