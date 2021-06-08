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

  // Magic header
  auto uBuffer = driver->GetNextBytes(4);
  if (!checkMagicNumber(std::move(uBuffer))) {
    auto error = generateError(fatal, unrecognizedHeader, 0);
    module.addError(error);
    return -1;
  }

  // Version number
  uBuffer = driver->GetNextBytes(4);
  if (!checkVersion(std::move(uBuffer))) {
    auto error = generateError(fatal, unrecognizedVersion, 4);
    module.addError(error);
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
} // namespace antiwasm
