#include "module_parser.hpp"

using namespace std;
namespace antiwasm {

int parse(const char *classFile) {
  shared_ptr<Driver> driver = Driver::GetInstance();
  if (!driver->OpenFile(classFile)) {
    BOOST_LOG_TRIVIAL(error) << "[scanner] Cannot open file";
    return -1;
  }

  // Generate Module
  Module module(driver->GetFileSize());

  if(!validateModuleHeader(module)) {
    // TODO invalid module
    return -1;
  }

  // Sections
  while (!driver->HasReachedFileSize(2)) {
    auto sectionPosition = driver->GetCurrentPos();
    auto nextSectionHeader = driver->GetNextSectionHeader();
    auto sectionSize = transformLeb128ToUnsignedInt32(nextSectionHeader.get() + 1);
    auto nextSectionContent = driver->GetNextBytes(sectionSize);
    auto nextSection =
        parseNextSection(nextSectionHeader.get()[0], sectionSize, nextSectionContent.get(), sectionPosition);

    BOOST_LOG_TRIVIAL(trace) << "[scanner] Id: " << hex << (int)(nextSectionHeader.get()[0]);
    BOOST_LOG_TRIVIAL(trace) << "[scanner] Size: " << hex << sectionSize;

    if (nextSection.getSectionId() != UndefinedSectionId) {
      nextSection.displaySectionHeaderInfo();
      module.addSection(nextSection);
    } else { // TODO manage error
      break;
    }
  }
  driver->CloseFile();

  return 0;
}

bool validateModuleHeader(Module &module) {
  shared_ptr<Driver> driver = Driver::GetInstance();
  if (!driver->IsCurrentlyParsing()) {
    BOOST_LOG_TRIVIAL(error) << "[module_parser] Cannot parse section headers as there is no file being parsed.";
    module.addError(generateError(fatal, driverNotParsing, 0));
    return false;
  }

  // Magic header
  auto uBuffer = driver->GetNextBytes(4);
  if (!checkMagicNumber(std::move(uBuffer))) {
    module.addError(generateError(fatal, unrecognizedHeader, 0));
    return false;
  }

  // Version number
  uBuffer = driver->GetNextBytes(4);
  if (!checkVersion(std::move(uBuffer))) {
    module.addError(generateError(fatal, unrecognizedVersion, 0));
    return false;
  }
  return true;
}


bool parseSectionHeaderMap(Module &module) {
  shared_ptr<Driver> driver = Driver::GetInstance();
  if (!driver->IsCurrentlyParsing()) {
    BOOST_LOG_TRIVIAL(error) << "[module_parser] Cannot parse section headers as there is no file being parsed.";
    module.addError(generateError(fatal, driverNotParsing, 0));
    return false;
  }

  // TODO
  return true;
}


} // namespace antiwasm
