#pragma once 
#include <variant>
#include <map>
#include <tgbot/tgbot.h>
#include "config.hpp"

class _Keyboard 
{
    public:
    _Keyboard(const _Config& __cfg)
    : _M_cfg(__cfg) {}
    TgBot::ReplyKeyboardMarkup::Ptr
    keyboard_creator(const bool& __enable_configuration, const bool& __is_admin);
    private:
    _Config _M_cfg;
    void
    keyboard_config(std::map<std::string, std::variant<std::string, bool>>& __fields,
                    TgBot::KeyboardButton::Ptr& __button);
    void
    keyboard_config(std::map<std::string, std::variant<std::string, bool>>& __fields,
                    TgBot::ReplyKeyboardMarkup::Ptr& __kb);

};
