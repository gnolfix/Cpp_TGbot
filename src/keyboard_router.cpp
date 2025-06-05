#include "keyboard_router.hpp"



void
_Keyboard::keyboard_creator(const std::vector<std::vector<std::string>>& __buttons, TgBot::ReplyKeyboardMarkup::Ptr& __kb)
{
    for(size_t i=0;i<__buttons.size(); ++i)
    {
        std::vector<TgBot::KeyboardButton::Ptr> __row;
        for(size_t j=0;j<__buttons[i].size();++j)
        {
            auto __button = std::make_shared<TgBot::KeyboardButton>();
            __button->text = __buttons[i][j];
            __row.push_back(__button);
        }
            __kb->keyboard.push_back(__row);
    }
    return;
}
