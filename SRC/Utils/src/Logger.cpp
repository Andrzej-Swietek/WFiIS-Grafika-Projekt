#include "Logger.hpp"


Logger* Logger::instance = nullptr;

Logger* Logger::getInstance() {
    if (instance == nullptr) {
        instance = new Logger();
    }
    return instance;
}

void Logger::log(const char* message) {
    std::cout << message << std::endl;
}

void Logger::setLogFile(const std::string& logFile) {
    this->logFile = logFile;
}

void Logger::setLogOutput(LogOutput output) {
    this->output = output;
}
