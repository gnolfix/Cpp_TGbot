#pragma once
#include <string>
#include <vector>
#include <map>

struct config
{
    int _M_admin_id;
    std::string _M_svo_path;
    std::string _M_svo_mime;
    std::vector<std::vector<std::string>> _M_keyboard;
    std::map<std::string,std::string> _M_commands;
};


class config_loader
{
    public:
        static config
        load(const std::string& file);
};

