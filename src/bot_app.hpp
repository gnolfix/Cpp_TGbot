#pragma once
#include "config.hpp"
#include "command_router.hpp"
#include "bot_controller.hpp"
#include "keyboard_router.hpp"
#include "inline_keyboard_router.hpp"
#include "logger.hpp"


class _Bot_app
{
    public:
        explicit
        _Bot_app(const _Config& __cfg)
        : _M_cfg(__cfg), _M_logger(__cfg), 
        _M_bot(__cfg._M_bot_token),
        _M_command_router(__cfg, _M_bot),
        _M_inline_keyboard_router(__cfg),
        _M_keyboard_router(__cfg),
        _M_controller(__cfg, _M_bot, _M_logger)
        {}
        int 
        run();
    private:
        _Config _M_cfg;
        _Logger _M_logger;
        TgBot::Bot _M_bot;
        _Command _M_command_router;
        _Keyboard _M_keyboard_router;
        _Inline _M_inline_keyboard_router;
        _Bot_controller _M_controller;
};

