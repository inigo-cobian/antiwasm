#include "displayer.hpp"

namespace antiwasm {

LoggingLevel Displayer::loggingLevel_;

void Displayer::Log(LoggingLevel minLoggingLevel, const string &logMessage) {
  if (Displayer::loggingLevel_ >= minLoggingLevel) {
    cout << logMessage << endl;
  }
}

void Displayer::SetLoggingLevel(LoggingLevel loggingLevel) { Displayer::loggingLevel_ = loggingLevel; }

LoggingLevel Displayer::GetLoggingLevel() { return Displayer::loggingLevel_; }

} // namespace antiwasm