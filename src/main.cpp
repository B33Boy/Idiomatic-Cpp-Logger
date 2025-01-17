#include <iostream>
#include <thread>
#include <vector>

#include "logger.hpp"
#include "crtplogger.hpp"


void logMessages(Logger::BaseLogger const& logger, int thread_id)
{
    for (int i = 0; i < 100; i++)
        LOG(logger, Logger::Level::INFO, "Message:" + std::to_string(i) + " , thread:" + std::to_string(thread_id));
}

void logdemo1()
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
}

void logdemo2()
{
    CRTPLogger::ConsoleLogger file_logger;
    for (int i = 0; i < 100; i++)
    {
        file_logger.Log(Logger::Level::INFO, "Char: " + std::to_string(i));
    }
}

int main()
{
    /**
     *  Threadsafe Logging using virtual dispatch
     */
     // logdemo1();

    /**
      * CRTP based logging
      */
    logdemo2();

    return 0;
}