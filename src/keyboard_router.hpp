#pragma once 
#include <vector>
#include <tgbot/tgbot.h>

class _Keyboard
{
    public:
    void
    keyboard_creator(const std::vector<std::vector<std::string>>& __buttons, TgBot::ReplyKeyboardMarkup::Ptr& __kb);
    




};
