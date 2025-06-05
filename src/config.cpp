#include "config.hpp"
#include "nlohmann/json.hpp"
#include <filesystem>
#include <fstream>

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

    __cfg._M_admin_id = __json.at("admin_id").get<int>();
    __cfg._M_bot_token = __json.at("bot_token").get<std::string>();
    __cfg._M_svo_mime = __json.at("svo_mime").get<std::string>();
    __cfg._M_svo_path = __json.at("svo_path").get<std::string>();
    __cfg._M_keyboard = __json.at("keyboard").get<std::vector<std::vector<std::string>>>();
    __cfg._M_commands = __json.at("commands").get<std::vector<std::map<std::string, std::string>>>();

    return __cfg;
}
