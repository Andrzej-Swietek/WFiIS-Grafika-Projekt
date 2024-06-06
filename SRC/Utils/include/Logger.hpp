#pragma once
#include <iostream>
#include <ostream>
#include <fstream>
#include <string>
#include <any>

enum class LogLevel {
    INFO,
    WARNING,
    ERROR
};

enum class LogOutput {
    CONSOLE,
    FILE,
    BOTH
};

enum class Color {
    DEFAULT = 39,
    RED = 31,
    GREEN = 32,
    YELLOW = 33,
    BLUE = 34,
    MAGENTA = 35,
    CYAN = 36,
    WHITE = 37
};

/**
 * @class Logger
 * @brief Utility class standarizing logging in the app
 * @example 
 * ```cpp
 *    Logger* logger = Logger::getInstance();
 *    logger->log("Test message", nullptr);
 *    logger->log("Value", 42);
 * ```
 */
class Logger {
public:
    static Logger* getInstance();

    void log(const char* message);

    template <typename T>
    void log(const char* message, T value);

    void setLogFile(const std::string& logFile);

    void setLogOutput(LogOutput output);

private:
    Logger() = default;

    static Logger* instance;
    std::string logFile = "logs/logs.log";
    LogOutput output = LogOutput::CONSOLE;
};

template <typename T>
void Logger::log(const char* message, T value) {
    std::cout << message << ": " << value << std::endl;
}

template <>
void Logger::log(const char* message, void*) {
    std::cout << message << std::endl;
}