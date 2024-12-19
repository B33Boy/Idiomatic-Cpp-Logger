#include <gtest/gtest.h>
#include <iostream>
#include <sstream>
#include <functional>

#include "logger.hpp"

namespace LoggerTests
{

    TEST(ConsoleLogger, PrintsToConsole)
    {
        // Arrange
        Logger::ConsoleLogger logger{};

        std::stringstream ss;
        std::streambuf* cout_buffer = std::cout.rdbuf(ss.rdbuf());

        std::string expected = "[INFO] This is a info message.\n";

        // Act
        LOG(logger, Logger::Level::INFO, "This is a info message.");
        std::string actual = ss.str();

        // Assert
        EXPECT_EQ(expected, actual);

        // Cleanup
        std::cout.rdbuf(cout_buffer);
    }
}
