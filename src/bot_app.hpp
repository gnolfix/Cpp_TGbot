#pragma once
#include "config.hpp"


class bot_app
{
    public:
        explicit bot_app(config cfg);
        int run();


    private:
        config cfg_;
        tg_api api_;
        command_router router_;
        callback_router cbrouter_;
};

