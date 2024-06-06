#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <sstream>

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
 * @brief Utility class standardizing logging in the app
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

    void logTimeStamp();
    std::string getTimeStamp();

    static Logger* instance;
    std::string logFile = "rasterizer_application_logs.log";
    LogOutput output = LogOutput::FILE;
};

// Template definitions must be in the header file
template <typename T>
void Logger::log(const char* message, T value) {
    if (this->output == LogOutput::FILE || this->output == LogOutput::BOTH) {
        std::ofstream file(this->logFile, std::ios::app);
        file << "========================================\n";
        file << this->getTimeStamp() << " ";
        file << message << ": " << value << std::endl;
        file << "========================================\n";
        file.close();
    }
    if (this->output == LogOutput::CONSOLE || this->output == LogOutput::BOTH) {
        std::cout << "========================================\n";
        this->logTimeStamp();
        std::cout << message << ": " << value << std::endl;
        std::cout << "========================================\n";
    }
}

// Template specialization for void*
template <>
inline void Logger::log<void*>(const char* message, void*) {
    if (this->output == LogOutput::FILE || this->output == LogOutput::BOTH) {
        std::ofstream file(this->logFile, std::ios::app);
        file << "========================================\n";
        file << this->getTimeStamp() << " ";
        file << message << std::endl;
        file << "========================================\n";
        file.close();
    }
    if (this->output == LogOutput::CONSOLE || this->output == LogOutput::BOTH) {
        std::cout << "========================================\n";
        this->logTimeStamp();
        std::cout << message << std::endl;
        std::cout << "========================================\n";
    }
}