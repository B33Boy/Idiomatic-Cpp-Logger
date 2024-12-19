#include <iostream>
#include "logger.hpp"


int main()
{
    Logger::ConsoleLogger con_log{};

    LOG(con_log, Logger::Level::INFO, "This is a info message.");
    LOG(con_log, Logger::Level::DEBUG, "This is a debug message.");
    LOG(con_log, Logger::Level::WARNING, "This is a warning message.");

    return 0;
}