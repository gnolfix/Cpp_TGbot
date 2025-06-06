#include "logger.hpp"
#include <chrono>
#include <sstream>
#include <iomanip>


std::string
current_date_time()
{
    auto now = std::chrono::system_clock::now();
    std::time_t now_c = std::chrono::system_clock::to_time_t(now);

    std::tm tm{};
#ifdef _WIN32
    localtime_s(&tm, &now_c);
#else
    localtime_r(&now_c, &tm);
#endif

    std::ostringstream oss;
    oss << std::put_time(&tm, "%Y-%m-%d %H:%M:%S");
    return oss.str();
}

void
_Logger::logger(log_level __log_lvl,const std::string& __text)
{
    if(__log_lvl > current_log_level)
    {
        return;
    }

    std::cerr<< level_to_string(__log_lvl) <<" [" << current_date_time() << "] "<< __text << std::endl;
    if(_M_cfg._M_in_file)
    {
        std::string __log = level_to_string(__log_lvl)+" ["+current_date_time()+"] "+__text;
        std::ofstream file(".bot.log", std::ios::app);
       if (file.is_open())
        {
        file << __log << std::endl; 
        file.close();
        } 
    }
       return;
}
std::string
_Logger::level_to_string(log_level __log_lvl)
{
    switch(__log_lvl)
    {
        case ERROR: return "ERROR";
        case WARNING: return "WARNING";
        case INFO: return "INFO";
        default: return "UNKNOWN";
    }
}
void
_Logger::set_log_level(log_level __log_lvl)
{
    current_log_level = __log_lvl;
}
