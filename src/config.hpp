#pragma once
#include <string>
#include <vector>
#include <map>

struct _Config
{
    int _M_admin_id;
    std::string _M_svo_path;
    std::string _M_bot_token;
    std::string _M_svo_mime;
    std::vector<std::vector<std::string>> _M_keyboard;
    std::vector<std::map<std::string,std::string>> _M_commands;
};


class _Config_loader
{
    public:
        static _Config
        load(const std::string& file);
};

