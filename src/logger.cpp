#include "logger.hpp"

namespace Logger
{
    auto to_string(Level const& level) -> std::string
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
}

