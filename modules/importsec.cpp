#include "importsec.hpp"
namespace antiwasm {

ImportSection::ImportSection(int size, uint8_t *content, int initialPos)
    : Section(SectionId::ImportId, size, content, initialPos) {
  BOOST_LOG_TRIVIAL(debug) << "[importsec] Creating a Import Section";
}

ImportSection::~ImportSection() = default;

void ImportSection::addImport(const Import &import) { importVector.push_back(import); }

vector<Memtype> ImportSection::getImportVector() { return vector<Memtype>(); }

void ImportSection::displaySectionHeaderInfo() {
  cout << "  Import | start=" << hex << initialPos_ << " size=" << hex << size_ << endl;
}

void ImportSection::displaySectionContentInfo() {
  cout << "  Import | start=" << hex << initialPos_ << " size=" << hex << size_ << " (" << importVector.size()
       << ") imports" << endl;

  size_t index = 0;
  for (const auto &import : importVector) {
    stringstream importAsText;
    importAsText << "( import \"" << import.module.name << "\" \"" << import.name.name << "\"\n";

    switch (import.importDescType) {
    case ImportFunc:
      // TODO wasm-objdump gives names to the functions
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
      cout << "error"; // TODO
    }

    importAsText << ")";
    cout << importAsText.str() << endl;
  }
}

} // namespace antiwasm