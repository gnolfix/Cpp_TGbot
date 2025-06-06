#include "bot_app.hpp"

int 
_Bot_app::run()
{
    _M_command_router.commands_creator();
    auto __kb = _M_keyboard_router.keyboard_creator(true, false);
    auto __inline_kb = _M_inline_keyboard_router.inline_keyboard_creator();
    _M_controller.message_handler();
    _M_controller.start_handler(__kb, __inline_kb);
    _M_controller.command_handler(__kb);
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


