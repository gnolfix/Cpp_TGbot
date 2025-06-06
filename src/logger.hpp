#pragma once 
#include <iostream>
#include <fstream>
#include <string>
#include "config.hpp"

class _Logger
{
    public:
        _Logger(const _Config& __cfg)
        : _M_cfg(__cfg) {}
        enum log_level
        {
            ERROR = 1,
            WARNING = 2,
            INFO = 3
        };
        void
        logger(log_level __log_lvl, const std::string& __text);
        void
        set_log_level(log_level __log_lvl);
    private:
        _Config _M_cfg;
        log_level current_log_level = INFO;
        std::string 
        level_to_string(log_level __log_lvl);

};
