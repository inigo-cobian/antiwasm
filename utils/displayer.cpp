#include "displayer.hpp"

using namespace std;
namespace antiwasm {

LoggingLevel Displayer::loggingLevel_;
SectionId Displayer::sectionToDisplay{ErrorId};

void Displayer::Log(LoggingLevel minLoggingLevel, const string &logMessage) {
  if (Displayer::loggingLevel_ >= minLoggingLevel) {
    cout << logMessage << endl;
  }
}

void Displayer::SetLoggingLevel(LoggingLevel loggingLevel) { Displayer::loggingLevel_ = loggingLevel; }

LoggingLevel Displayer::GetLoggingLevel() { return Displayer::loggingLevel_; }

bool Displayer::setSectionToDisplay(int sectionToDisplay_) {
  if(sectionToDisplay_ >= 0 && sectionToDisplay_ <= 12) {
    Displayer::sectionToDisplay = static_cast<SectionId>(sectionToDisplay_ - '0');
    return true;
  }
  return false;
}

SectionId Displayer::getSectionToDisplay() { return Displayer::sectionToDisplay; }

} // namespace antiwasm