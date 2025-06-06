#include "keyboard_router.hpp"



TgBot::ReplyKeyboardMarkup::Ptr
_Keyboard::keyboard_creator(const bool& __enable_configuration, const bool& __is_admin)
{
    const auto& __buttons = __is_admin
        ? _M_cfg._M_keyboard_admin
        : _M_cfg._M_keyboard_user;

    auto __kb = std::make_shared<TgBot::ReplyKeyboardMarkup>();

    for(size_t i=0;i<__buttons.size(); ++i)
    {
        std::vector<TgBot::KeyboardButton::Ptr> __row;
        for(size_t j=0;j<__buttons[i].size();++j)
        {
            auto __button = std::make_shared<TgBot::KeyboardButton>();
            __button->text = __buttons[i][j];
            if(_M_cfg._M_developer_mode && __enable_configuration)
            {
                auto& __fields = __is_admin
                    ? _M_cfg._M_keyboard_fields_admin
                    : _M_cfg._M_keyboard_fields_user;
                this->keyboard_config(__fields, __button);
            }
            __row.push_back(__button);
        }
        __kb->keyboard.push_back(__row);
    }
    if(_M_cfg._M_developer_mode && __enable_configuration)
    {
        auto& __fields = __is_admin
            ? _M_cfg._M_keyboard_fields_admin
            : _M_cfg._M_keyboard_fields_user;
        this->keyboard_config(__fields, __kb);
    }
    return __kb;
}

void
_Keyboard::keyboard_config(std::map<std::string, std::variant<std::string, bool>>& __fields, TgBot::KeyboardButton::Ptr& __button)
{
    if(std::holds_alternative<bool>(__fields["contact"]))
    {
        __button->requestContact = std::get<bool>(__fields["contact"]);
    }
    else
    {
        __button->requestContact = false;
    }
    if(std::holds_alternative<bool>(__fields["location"]))
    {
        __button->requestLocation = std::get<bool>(__fields["location"]);
    }
    else 
    {
        __button->requestLocation = false;
    }
}

void
_Keyboard::keyboard_config(std::map<std::string, std::variant<std::string, bool>>& __fields, TgBot::ReplyKeyboardMarkup::Ptr& __kb)
{
    if(std::holds_alternative<bool>(__fields["resize"]))
    {
        __kb->resizeKeyboard = std::get<bool>(__fields["resize"]);
    } 
    else
    {
        __kb->resizeKeyboard = false;  
    }
    if(std::holds_alternative<std::string>(__fields["placeholder"]))
    {
        __kb->inputFieldPlaceholder = std::get<std::string>(__fields["placeholder"]);
    }
    return;
}
