#ifndef LOG_LEVELS_HPP
#define LOG_LEVELS_HPP

namespace Logger
{
    enum class Level
    {
        DEBUG,
        INFO,
        WARNING,
        ERROR,
        CRITICAL
    };

    constexpr auto to_string(Level const& level) -> const char*
    {
        switch (level)
        {
        case Level::DEBUG:
            return "[DEBUG] ";
        case Level::INFO:
            return "[INFO] ";
        case Level::WARNING:
            return "[WARNING] ";
        case Level::ERROR:
            return "[ERROR] ";
        case Level::CRITICAL:
            return "[CRITICAL] ";
        default:
            return "UNKNOWN";
        }
    }

    constexpr const char* LEVEL_INFO = to_string(Level::INFO);
    constexpr const char* LEVEL_DEBUG = to_string(Level::DEBUG);
    constexpr const char* LEVEL_WARN = to_string(Level::WARNING);
    constexpr const char* LEVEL_CRIT = to_string(Level::CRITICAL);
    constexpr const char* LEVEL_ERROR = to_string(Level::ERROR);
}

#endif