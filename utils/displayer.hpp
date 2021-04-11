#ifndef ANTIWASM_DISPLAYER_HPP
#define ANTIWASM_DISPLAYER_HPP

#include "logging_levels.hpp"
#include <iostream>

class Displayer { // TODO general
private:
  static LoggingLevel loggingLevel_;

public:
  static void Log(LoggingLevel minLoggingLevel, const std::string &logMessage);

  static void SetLoggingLevel(LoggingLevel loggingLevel);

  static LoggingLevel GetLoggingLevel();
};

#endif // ANTIWASM_DISPLAYER_HPP
