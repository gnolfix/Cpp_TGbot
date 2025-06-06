#pragma once
#include <string>
#include <vector>
#include <variant>
#include <map>

struct _Config
{
    int _M_admin_id;
    bool _M_developer_mode;
    bool _M_in_file;
    std::string _M_svo_path;
    std::string _M_bot_token;
    std::string _M_svo_mime;
    std::vector<std::vector<std::string>> _M_keyboard_user;
    std::vector<std::vector<std::string>> _M_keyboard_admin;
    std::vector<std::map<std::string, std::string>> _M_commands;
    std::vector<std::map<std::string,std::string>> _M_command_router;
    std::map<std::string, std::variant<std::string, bool>> _M_keyboard_fields_user;
    std::map<std::string, std::variant<std::string, bool>> _M_keyboard_fields_admin;
    std::vector<std::vector<std::map<std::string, std::string>>> _M_inline_keyboard;


    _Config()
    : _M_admin_id(0), _M_developer_mode(false), _M_in_file(false) {}
};


class _Config_loader
{
    public:
        static _Config
        load(const std::string& file);
};

