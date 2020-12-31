#include "../includes/logger.hpp"

LoggingLevel Logger::loggingLevel_;

Logger::~Logger() {

}

Logger::Logger() {
    SetLoggingLevel(LoggingLevel::INFO);
}

void Logger::Log(LoggingLevel minLoggingLevel, std::string logMessage) {
    if(Logger::loggingLevel_ >= minLoggingLevel) {
        std::cout << logMessage << std::endl;
    }
}

void Logger::SetLoggingLevel(LoggingLevel loggingLevel) {
    Logger::loggingLevel_ = loggingLevel;
}

LoggingLevel Logger::GetLoggingLevel() {
    return Logger::loggingLevel_;
}
