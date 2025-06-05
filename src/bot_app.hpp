#pragma once
#include "config.hpp"
#include "command_router.hpp"
#include "keyboard_router.hpp"


class _Bot_app
{
    public:
        explicit
        _Bot_app(const _Config& __cfg)
        : _M_cfg(__cfg), _M_bot(__cfg._M_bot_token),
        _M_kb(std::make_shared<TgBot::ReplyKeyboardMarkup>()){}
        int 
        run();
    private:
        _Config _M_cfg;
        TgBot::Bot _M_bot;
        TgBot::ReplyKeyboardMarkup::Ptr _M_kb;
        _Command _M_command_router;
        _Keyboard _M_keyboard_router;
        
};

