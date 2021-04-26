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
  // TODO
  Section::displaySectionContentInfo();
}

} // namespace antiwasm