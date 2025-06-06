#pragma once
#include <variant>
#include <map>
#include <tgbot/tgbot.h>
#include "config.hpp"



class _Inline
{
    public:
    _Inline(const _Config& __cfg)
    : _M_cfg(__cfg) {}
    TgBot::InlineKeyboardMarkup::Ptr
    inline_keyboard_creator(const bool& __is_url);



    private:
    _Config _M_cfg;

};
