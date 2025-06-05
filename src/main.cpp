#include "bot_app.hpp"
#include <tgbot/tgbot.h>

int main()
{
    _Config __cfg = _Config_loader::load("config.json");
    _Bot_app app(__cfg);
    app.run();
   return 0;
}
