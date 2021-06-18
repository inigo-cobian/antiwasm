#include "importsec.hpp"

namespace antiwasm {

ImportSection::ImportSection(int size, uint8_t *content, int initialPos)
    : Section(SectionId::ImportId, size, content, initialPos) {
  BOOST_LOG_TRIVIAL(debug) << "[importsec] Creating a Import Section";
}

ImportSection::~ImportSection() = default;

void ImportSection::addImport(const Import &import) { importVector.push_back(import); }

std::vector<Import> ImportSection::getImportVector() { return importVector; }

void ImportSection::displaySectionHeaderInfo() {
  std::cout << "  Import | start=" << std::hex << initialPos_ << " size=" << std::hex << size_ << std::endl;
}

void ImportSection::displaySectionContentInfo() {
  std::cout << "  Import | start=" << std::hex << initialPos_ << " size=" << std::hex << size_ << " ("
            << importVector.size() << ") imports" << std::endl;

  size_t index = 0;
  for (const auto &import : importVector) {
    std::stringstream importAsText;
    importAsText << "( import \"" << import.module.name << "\" \"" << import.name.name << "\"\n";

    switch (import.importDescType) {
    case ImportFunc:
      importAsText << " ( func $" << import.importDesc.typeIdx << " )\n";
      break;
    case ImportTable:
      importAsText << " " << import.importDesc.tabletype->getAsText() << "\n";
      break;
    case ImportMemtype:
      importAsText << " " << import.importDesc.memtype->getAsText() << "\n";
      break;
    case ImportGlobaltype:
      importAsText << " " << import.importDesc.globaltype->getAsText() << "\n";
      break;
    default:
      std::cout << "error"; // TODO
    }

    importAsText << ")";
    std::cout << importAsText.str() << std::endl;
  }
}

} // namespace antiwasm