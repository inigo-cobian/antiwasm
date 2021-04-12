#include "displayer.hpp"

namespace antiwasm {

LoggingLevel Displayer::loggingLevel_;

void Displayer::Log(LoggingLevel minLoggingLevel,
                    const std::string &logMessage) {
  if (Displayer::loggingLevel_ >= minLoggingLevel) {
    std::cout << logMessage << std::endl;
  }
}

void Displayer::SetLoggingLevel(LoggingLevel loggingLevel) {
  Displayer::loggingLevel_ = loggingLevel;
}

LoggingLevel Displayer::GetLoggingLevel() { return Displayer::loggingLevel_; }

} // namespace antiwasm