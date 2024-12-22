#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <mutex>

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

    auto to_string(Level const& level) -> std::string;

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