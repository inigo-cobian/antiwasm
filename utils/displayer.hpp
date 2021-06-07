#ifndef ANTIWASM_DISPLAYER_HPP
#define ANTIWASM_DISPLAYER_HPP

#include "logging_levels.hpp"
#include "section.hpp" // for SectionId
#include <iostream>

namespace antiwasm {

class Displayer { // TODO general
private:
  static LoggingLevel loggingLevel_;
  static SectionId sectionToDisplay;

public:
  static void Log(LoggingLevel minLoggingLevel, const std::string &logMessage);

  static void SetLoggingLevel(LoggingLevel loggingLevel);

  static LoggingLevel GetLoggingLevel();

  static bool setSectionToDisplay(int sectionToDisplay_);

  static SectionId getSectionToDisplay();
};

} // namespace antiwasm
#endif // ANTIWASM_DISPLAYER_HPP
