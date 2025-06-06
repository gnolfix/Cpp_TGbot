#pragma once
#include "config.hpp"
#include "logger.hpp"
#include <tgbot/tgbot.h>

class _Bot_controller
{
    public:
        _Bot_controller(const _Config& __cfg, TgBot::Bot& __bot, _Logger& __log)
        : _M_logger(__log), _M_cfg(__cfg), _M_bot(__bot) {}
        void
        message_handler();
        void
        start_handler(TgBot::ReplyKeyboardMarkup::Ptr& __kb, TgBot::InlineKeyboardMarkup::Ptr& __inline_kb);
        void
        command_handler(const TgBot::ReplyKeyboardMarkup::Ptr& __kb);
        void
        send_text(int64_t __chat_id, const std::string& __text);
        void
        send_keyboard(int64_t __chat_id, const std::string& __text, const TgBot::ReplyKeyboardMarkup::Ptr& __kb);
        void
        send_keyboard(int64_t __chat_id, const std::string& __text, const TgBot::InlineKeyboardMarkup::Ptr& __kb);
         



    private:
        _Logger _M_logger;
        const _Config& _M_cfg;
        TgBot::Bot& _M_bot;

};
