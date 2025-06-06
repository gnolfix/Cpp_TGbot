#include "bot_controller.hpp"
#include "logger.hpp"

void
_Bot_controller::message_handler()
{
    _M_bot.getEvents().onAnyMessage([this](TgBot::Message::Ptr __msg)
    {
        if (StringTools::startsWith(__msg->text, "/start"))
        {
            return;
        }
        _M_logger.logger(_M_logger.INFO,__msg->from->firstName+"("+std::to_string(__msg->from->id)+")"+": "+__msg->text);
    });
    return;
}
void
_Bot_controller::start_handler( TgBot::ReplyKeyboardMarkup::Ptr& __kb, TgBot::InlineKeyboardMarkup::Ptr& __inline_kb)
{
    _M_bot.getEvents().onCommand("start", [this, __kb](TgBot::Message::Ptr __msg)
    {
        _M_logger.logger(_M_logger.INFO,__msg->from->firstName+"("+std::to_string(__msg->from->id)+")"+": "+"Отправил мерзки /start фе");
        this->send_keyboard(__msg->from->id, "Hello!", __kb);
    });
    _M_bot.getEvents().onCommand("zov", [this, __inline_kb](TgBot::Message::Ptr __msg)
    {
        _M_logger.logger(_M_logger.INFO,__msg->from->firstName+"("+std::to_string(__msg->from->id)+")"+": "+"Отправил мерзки /start фе");
        this->send_keyboard(__msg->from->id, "Hello!", __inline_kb);
    });
        return;
}
void
_Bot_controller::command_handler(const TgBot::ReplyKeyboardMarkup::Ptr& __kb)
{
    for(const auto& __commands_map : _M_cfg._M_commands)
    {
        for(const auto & [command, text] : __commands_map)
        {
            if(command == "start")
            { 
                std::cerr << "[PRANK] Команда /start вызвана в неправильном месте! Вызываем SIGFOULT\n";
                (*(int*)nullptr) = 0;
            }
            _M_bot.getEvents().onCommand(command, [this, text](TgBot::Message::Ptr __msg)
            {
                this->send_text(__msg->from->id, text);
            });
        }
    }
    return;
}
void
_Bot_controller::send_keyboard(int64_t __chat_id, const std::string& __text, const TgBot::InlineKeyboardMarkup::Ptr& __kb)
{
    _M_bot.getApi().sendMessage(__chat_id, __text, nullptr, nullptr, __kb);
    return;
}
void
_Bot_controller::send_keyboard(int64_t __chat_id, const std::string& __text, const TgBot::ReplyKeyboardMarkup::Ptr& __kb)
{
    _M_bot.getApi().sendMessage(__chat_id, __text, nullptr, nullptr, __kb);
    return;
}
void
_Bot_controller::send_text(int64_t __chat_id, const std::string& __text)
{
    _M_bot.getApi().sendMessage(__chat_id, __text, nullptr, nullptr, nullptr);
    return;
}

