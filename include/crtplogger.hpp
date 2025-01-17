#ifndef CRTPLOGGER_HPP
#define CRTPLOGGER_HPP

#include <iostream>
#include <string>

#include "logger.hpp"
#include "log_levels.hpp"

namespace CRTPLogger
{
    template <typename Derived>
    class CRTPLogger
    {
    public:
        void Log(Logger::Level const& level, std::string const& message) const
        {
            std::cout << "[" << static_cast<Derived const*>(this)->log_type() << "] "
                << "" << Logger::to_string(level) << " " << message << "\n";
        }
    };

    class ConsoleLogger : public CRTPLogger<ConsoleLogger>
    {
    public:
        char const* log_type() const
        {
            return "ConsoleLogger";
        }
    };

    class FileLogger : public CRTPLogger<FileLogger>
    {
    public:
        char const* log_type() const
        {
            return "FileLogger";
        }
    };
}
#endif