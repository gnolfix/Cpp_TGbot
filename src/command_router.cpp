#include "command_router.hpp"

void 
_Command::commands_creator(std::vector<std::map<std::string,std::string>>& __commands, TgBot::Bot& __bot)
{
    std::vector<TgBot::BotCommand::Ptr> __row;
    for(size_t i=0;i<__commands.size();++i)
    {
        for(const auto& [command, description] : __commands[i])
        {
            auto __cmd = std::make_shared<TgBot::BotCommand>();
            __cmd->command = command;
            __cmd->description = description;
            __row.push_back(__cmd);
        }
    }
    __bot.getApi().setMyCommands(__row);
    return;
}
