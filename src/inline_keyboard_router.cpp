#include "inline_keyboard_router.hpp"

TgBot::InlineKeyboardMarkup::Ptr
_Inline::inline_keyboard_creator()
{
    auto __kb = std::make_shared<TgBot::InlineKeyboardMarkup>();

    for(const auto& __inner_vec : _M_cfg._M_inline_keyboard)
    {
        std::vector<TgBot::InlineKeyboardButton::Ptr> __row;
        for(const auto& __map_item : __inner_vec)
        {
            for(const auto& [ key, value] : __map_item)
            {
                auto __button = std::make_shared<TgBot::InlineKeyboardButton>();
                __button->text = key;
                __button->callbackData = value;
                __row.push_back(__button);
            }
        }
        __kb->inlineKeyboard.push_back(__row);
    }

    return __kb;
}
