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

bool Displayer::setSectionToDisplay(std::string sectionToDisplay_) {
  if(boost::iequals(sectionToDisplay_, "custom")) {
    Displayer::sectionToDisplay = SectionId::CustomId;
    return true;
  }
  if(boost::iequals(sectionToDisplay_, "type")) {
    Displayer::sectionToDisplay = SectionId::TypeId;
    return true;
  }
  if(boost::iequals(sectionToDisplay_, "import")) {
    Displayer::sectionToDisplay = SectionId::ImportId;
    return true;
  }
  if(boost::iequals(sectionToDisplay_, "function")) {
    Displayer::sectionToDisplay = SectionId::FunctionId;
    return true;
  }
  if(boost::iequals(sectionToDisplay_, "table")) {
    Displayer::sectionToDisplay = SectionId::TableId;
    return true;
  }
  if(boost::iequals(sectionToDisplay_, "memory")) {
    Displayer::sectionToDisplay = SectionId::MemoryId;
    return true;
  }
  if(boost::iequals(sectionToDisplay_, "global")) {
    Displayer::sectionToDisplay = SectionId::GlobalId;
    return true;
  }
  if(boost::iequals(sectionToDisplay_, "export")) {
    Displayer::sectionToDisplay = SectionId::ExportId;
    return true;
  }
  if(boost::iequals(sectionToDisplay_, "start")) {
    Displayer::sectionToDisplay = SectionId::StartId;
    return true;
  }
  if(boost::iequals(sectionToDisplay_, "element")) {
    Displayer::sectionToDisplay = SectionId::ElementId;
    return true;
  }
  if(boost::iequals(sectionToDisplay_, "code")) {
    Displayer::sectionToDisplay = SectionId::CodeId;
    return true;
  }
  if(boost::iequals(sectionToDisplay_, "data")) {
    Displayer::sectionToDisplay = SectionId::DataId;
    return true;
  }
  if(boost::iequals(sectionToDisplay_, "datacount")) {
    Displayer::sectionToDisplay = SectionId::DataCountId;
    return true;
  }
  return false;
}

SectionId Displayer::getSectionToDisplay() { return Displayer::sectionToDisplay; }

} // namespace antiwasm