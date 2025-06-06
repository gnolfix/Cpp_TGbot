#pragma once

#include <nlohmann/json.hpp>
#include <variant>
#include <string>
#include <stdexcept>

template <>
struct nlohmann::adl_serializer<std::variant<std::string, bool>>
{
    static void from_json(const nlohmann::json& j, std::variant<std::string, bool>& v)
    {
        if (j.is_boolean())
        {
            v = j.get<bool>();
        }
        else if (j.is_string())
        {
            v = j.get<std::string>();
        }
        else
        {
            throw std::runtime_error("Invalid type for variant<std::string, bool>");
        }
    }

    static void to_json(nlohmann::json& j, const std::variant<std::string, bool>& v)
    {
        if (std::holds_alternative<bool>(v))
        {
            j = std::get<bool>(v);
        }
        else if (std::holds_alternative<std::string>(v))
        {
            j = std::get<std::string>(v);
        }
    }
};
