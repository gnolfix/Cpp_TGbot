#pragma once 
#include <tgbot/tgbot.h>
#include <map>
#include <vector>
#include <string>


class _Command
{
    public:
    void 
    commands_creator(std::vector<std::map<std::string,std::string>>& __commands, TgBot::Bot& __bot);
    private:

};
