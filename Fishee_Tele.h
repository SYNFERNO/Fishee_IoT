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
    if (msg.text == "/help")
      answer = "So you need _help_, uh? me too! use /start, /status, /feed";
    else if (msg.text == "/start")
    {
      answer = "Selamat datang "  + msg.from_name +  "di Fishee Bot";
    }
    else if (msg.text == "/status")
    {
      answer = "All is good here, thanks for asking!";
    }
    else if (msg.text == "/feed")
    {
      openfeeder();
      feeder();
      answer = "Beri makan ikan dimulai!";
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
                            "{\"command\":\"feed\", \"description\":\"Beri makanan ikans\"}"
                            "]");
  bot.setMyCommands(commands);
}

#endif
