#include "config.hpp"
#include "nlohmann/json.hpp"
#include "nlohmann_variant_fix.hpp"
#include <filesystem>
#include <fstream>
#include <variant>

_Config
_Config_loader::load(const std::string& file)
{
    if(!std::filesystem::exists(file))
    {
        throw std::runtime_error("Config file not found: " + file);
    }

    std::ifstream __file(file);
    nlohmann::json __json;

    __file >> __json;

    _Config __cfg;

    if(__json.contains("developer_mode"))
    {
        __cfg._M_developer_mode = __json.at("developer_mode").get<bool>();
        if(__cfg._M_developer_mode)
        {
            __cfg._M_keyboard_fields_user = __json.at("keyboard_fields_user").get<std::map<std::string, std::variant<std::string, bool>>>();
            __cfg._M_keyboard_fields_admin = __json.at("keyboard_fields_admin").get<std::map<std::string, std::variant<std::string, bool>>>();
            __cfg._M_in_file = __json.at("in_file").get<bool>();
        }
    }
    __cfg._M_admin_id = __json.at("admin_id").get<int>();
    __cfg._M_bot_token = __json.at("bot_token").get<std::string>();
    __cfg._M_svo_mime = __json.at("svo_mime").get<std::string>();
    __cfg._M_svo_path = __json.at("svo_path").get<std::string>();
    __cfg._M_keyboard_user = __json.at("keyboard_user").get<std::vector<std::vector<std::string>>>();
    __cfg._M_keyboard_admin = __json.at("keyboard_admin").get<std::vector<std::vector<std::string>>>();
    __cfg._M_inline_keyboard = __json.at("inline_keyboard").get<std::vector<std::vector<std::map<std::string, std::string>>>>();
    __cfg._M_command_router = __json.at("command_router").get<std::vector<std::map<std::string, std::string>>>();
    __cfg._M_commands = __json.at("commands").get<std::vector<std::map<std::string, std::string>>>();

    return __cfg;
}
