#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <mutex>
#include "log_levels.hpp"

namespace Logger
{
    class BaseLogger
    {
    public:
        virtual void Log(std::string const& message, Level level) const = 0;
        virtual ~BaseLogger() = default;
    };

    class ConsoleLogger : public BaseLogger
    {
    public:
        void Log(std::string const& message, Level level) const override;
    private:
        mutable std::mutex mutex_;
    };

#define LOG(logger, level, message) logger.Log(message, level);

}
#endif