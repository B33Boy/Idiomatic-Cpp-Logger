#include <iostream>
#include <thread>
#include <vector>

#include "logger.hpp"


void logMessages(Logger::BaseLogger const& logger, int thread_id)
{
    for (int i = 0; i < 100; i++)
        LOG(logger, Logger::Level::INFO, "Message:" + std::to_string(i) + " , thread:" + std::to_string(thread_id));
}


int main()
{
    Logger::ConsoleLogger con_log{};

    // LOG(con_log, Logger::Level::INFO, "This is a info message.");
    // LOG(con_log, Logger::Level::DEBUG, "This is a debug message.");
    // LOG(con_log, Logger::Level::WARNING, "This is a warning message.");

    int const numThreads{ 2 };
    std::vector<std::thread> threads;
    for (int i = 0; i < numThreads; i++)
        threads.emplace_back(logMessages, std::ref(con_log), i);

    for (auto& thread : threads)
        thread.join();

    return 0;
}