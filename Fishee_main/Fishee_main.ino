#include "Fishee_Setup.h"

const unsigned long BOT_MTBS = 200; // mean time between scan messages
unsigned long bot_lasttime; // last time messages' scan has been done

void setup()
{
  Serial.begin(115200);
  Serial.println();

  
  init_wifi();
  init_suhu();
  bot_setup();
  init_servo();
  init_stepper;
}

void loop()
{
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
}
