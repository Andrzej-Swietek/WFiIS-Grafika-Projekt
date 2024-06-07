#include "Logger.hpp"

// Initialize the static member
Logger* Logger::instance = nullptr;

Logger* Logger::getInstance() {
    if (instance == nullptr) {
        instance = new Logger();
    }
    return instance;
}

void Logger::log(const char* message) {
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

void Logger::setLogFile(const std::string& logFile) {
    this->logFile = logFile;
}

void Logger::setLogOutput(LogOutput output) {
    this->output = output;
}

void Logger::logTimeStamp() {
    std::cout << "[" << this->getTimeStamp() << "] ";
}

std::string Logger::getTimeStamp() {
    std::time_t now = std::time(nullptr);
    char buffer[100];
    ctime_s(buffer, sizeof(buffer), &now);
    std::string timeStamp(buffer);
    timeStamp.pop_back(); // Remove trailing newline character
    return timeStamp;
}
