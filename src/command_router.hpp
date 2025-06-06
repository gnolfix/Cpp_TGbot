#pragma once 
#include <tgbot/tgbot.h>
#include "config.hpp"
#include <map>
#include <vector>
#include <string>

class _Command
{
    public:
    _Command(const _Config& __cfg, TgBot::Bot& __bot)
    : _M_cfg(__cfg), _M_bot(__bot) {}
    void 
    commands_creator();
    private:
    const _Config& _M_cfg;
    TgBot::Bot& _M_bot;
};
