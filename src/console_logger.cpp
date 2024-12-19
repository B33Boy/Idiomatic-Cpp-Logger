#include <iostream>

#include "logger.hpp"

namespace Logger
{
    void ConsoleLogger::Log(std::string const& message, Level level) const
    {
        std::cout << Logger::to_string(level) << message << std::endl;
    }
}