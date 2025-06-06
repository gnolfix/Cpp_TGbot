#include "command_router.hpp"

void 
_Command::commands_creator()
{
    std::vector<TgBot::BotCommand::Ptr> __row;
    for(size_t i=0;i<_M_cfg._M_command_router.size();++i)
    {
        for(const auto& [command, description] : _M_cfg._M_command_router[i])
        {
            auto __cmd = std::make_shared<TgBot::BotCommand>();
            __cmd->command = command;
            __cmd->description = description;
            __row.push_back(__cmd);
        }
    }
    _M_bot.getApi().setMyCommands(__row);
    return;
}
