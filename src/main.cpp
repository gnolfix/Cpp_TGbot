#include "config.hpp"
#include <iostream>

int main()
{
    config __cfg = config_loader::load("config.json");
    std::cout << __cfg._M_admin_id << ", " << __cfg._M_svo_path << ", " << __cfg._M_svo_mime << ", " << __cfg._M_keyboard[0][1] << std::endl;


    return 0;
}
