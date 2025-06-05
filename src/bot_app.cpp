#include "bot_app.hpp"

int 
_Bot_app::run()
{
    std::map<std::string, std::string> i;
    _M_command_router.commands_creator(_M_cfg._M_commands, _M_bot);
    _M_keyboard_router.keyboard_creator(_M_cfg._M_keyboard,  _M_kb);
    
    _M_bot.getEvents().onCommand("start", [this](TgBot::Message::Ptr message) {
        _M_bot.getApi().sendMessage(message->chat->id, "Hi!", nullptr, nullptr, _M_kb);
    });
    _M_bot.getEvents().onAnyMessage([this](TgBot::Message::Ptr message) {
        printf("User wrote %s\n", message->text.c_str());
        if (StringTools::startsWith(message->text, "/start")) {
            return;
        }
        _M_bot.getApi().sendMessage(message->chat->id, "Your message is: " + message->text);
    });
    try {
        printf("Bot username: %s\n", _M_bot.getApi().getMe()->username.c_str());
        TgBot::TgLongPoll longPoll(_M_bot);
        while (true) {
            printf("Long poll started\n");
            longPoll.start();
        }
    } catch (TgBot::TgException& e) {
        printf("error: %s\n", e.what());
    }

    return 0;
}




