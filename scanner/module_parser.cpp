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

  if(!parseSectionHeaderMap(module)) {
    // TODO invalid section headers
    return -1;
  }

  int nThreads;
  MPI_Comm_size(MPI_COMM_WORLD, &nThreads);
  bool valid;
  if(nThreads == 4) {
    valid = multithreadParsing(module);
  } else {
    valid = singlethreadParsing(module);
  }
  driver->CloseFile();

  for (auto& [id, section] : module.getSectionMap()) {
    if (Displayer::hasToDisplaySection(id)) {
      section->displaySectionContentInfo();
    } else {
      section->displaySectionHeaderInfo();
    }
  }

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

  while (!driver->HasReachedFileSize(2)) {
    auto sectionPosition = driver->GetCurrentPos();
    auto nextSectionHeader = driver->GetNextSectionHeader();
    auto sectionSize = transformLeb128ToUnsignedInt32(nextSectionHeader.get() + 1);
    auto nextSectionContent = driver->GetNextBytes(sectionSize);

    auto sectionHeader = SectionHeader{
        static_cast<SectionId>(nextSectionHeader.get()[0]),
        sectionPosition,
        static_cast<int>(sectionSize),
        std::move(nextSectionContent)
    };

    module.addSectionHeader(sectionHeader);
    BOOST_LOG_TRIVIAL(trace) << "[scanner] Id: " << hex << (int)(nextSectionHeader.get()[0]);
    BOOST_LOG_TRIVIAL(trace) << "[scanner] Size: " << hex << sectionSize;

    /*
    if (nextSection.getSectionId() != UndefinedSectionId) {
      nextSection.displaySectionHeaderInfo();
      module.addSection(nextSection);
    } else { // TODO manage error
      break;
    }
     */
  }

  // TODO
  return true;
}

bool multithreadParsing(Module &module) {
  for (const auto & [sectionId, sectionHeader] : module.getSectionHeaderMap()) {
    std::cout << "%%%" << sectionId << std::endl;
    switch (sectionId) {
    case CustomId: // ignore
      break;
    case TypeId:
    case ImportId:
    case FunctionId:
    case CodeId:
    case StartId:
      addSectionHeaderToThread(0, sectionHeader);
      break;
    case TableId:
    case ElementId:
      addSectionHeaderToThread(1, sectionHeader);
      break;
    case MemoryId:
    case DataId:
    case DataCountId:
      addSectionHeaderToThread(2, sectionHeader);
      break;
    case GlobalId:
    case ExportId:
      addSectionHeaderToThread(3, sectionHeader);
      break;
    case UndefinedSectionId:
      return false;
    }
  }

  return true;
}

bool singlethreadParsing(Module &module) {
  for (const auto & [sectionId, sectionHeader] : module.getSectionHeaderMap()) {
    auto nextSection = parseNextSection(
        sectionHeader.id,
        sectionHeader.size,
        sectionHeader.content.get(),
        sectionHeader.pos);
    module.addSection(nextSection);
  }
  return true;
}

void addSectionHeaderToThread(int thread, const SectionHeader& sectionHeader) {
  std::cout << "XXX" << thread << "-" << sectionHeader.id << std::endl;
  if(!mapThreadSections.contains(thread)) {
    std::vector<SectionHeader> secHeaderVec;
    secHeaderVec.push_back(sectionHeader);
  } else {
    mapThreadSections.at(thread).push_back(sectionHeader);
  }
}
} // namespace antiwasm
