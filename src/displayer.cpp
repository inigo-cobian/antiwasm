#include "../includes/displayer.hpp"

LoggingLevel Displayer::loggingLevel_;

void Displayer::Log(LoggingLevel minLoggingLevel, std::string logMessage) {
    if (Displayer::loggingLevel_ >= minLoggingLevel) {
        std::cout << logMessage << std::endl;
    }
}

void Displayer::SetLoggingLevel(LoggingLevel loggingLevel) {
    Displayer::loggingLevel_ = loggingLevel;
}

LoggingLevel Displayer::GetLoggingLevel() {
    return Displayer::loggingLevel_;
}
