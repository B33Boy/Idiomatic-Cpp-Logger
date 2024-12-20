#include <gtest/gtest.h>
#include <iostream>
#include <sstream>
#include <functional>

#include "logger.hpp"

auto capture_output(std::function<void()> func) -> std::string
{
    std::stringstream ss;
    std::streambuf* cout_buffer = std::cout.rdbuf(ss.rdbuf());

    func();

    std::cout.rdbuf(cout_buffer);
    return ss.str();
}

namespace LoggerTests
{

    TEST(ConsoleLogger, PrintsToConsole)
    {
        // Arrange
        Logger::ConsoleLogger logger{};

        std::string expected = "[INFO] This is a info message.\n";

        // Act
        std::string actual = capture_output([&logger]() {
            LOG(logger, Logger::Level::INFO, "This is a info message.");
            });

        // Assert
        EXPECT_EQ(expected, actual);
    }
}
