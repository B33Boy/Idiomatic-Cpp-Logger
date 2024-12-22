#include <iostream>
#include <mutex>

#include "logger.hpp"

namespace Logger
{
    void ConsoleLogger::Log(std::string const& message, Level level) const
    {
        std::lock_guard<std::mutex> lock(mutex_);
        std::cout << Logger::to_string(level) << message << std::endl;
    }
}