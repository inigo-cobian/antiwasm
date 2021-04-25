#include "importsec.hpp"
namespace antiwasm {

ImportSection::ImportSection(int size, uint8_t *content, int initialPos)
    : Section(SectionId::MemoryId, size, content, initialPos) {
  BOOST_LOG_TRIVIAL(debug) << "[importsec] Creating a Import Section";
}

ImportSection::~ImportSection() = default;

void ImportSection::addImport(Import import) {
  // TODO
}
vector<Memtype> ImportSection::getImportVector() { return vector<Memtype>(); }

void ImportSection::displaySectionHeaderInfo() {
  // TODO
}

void ImportSection::displaySectionContentInfo() {
  // TODO
  Section::displaySectionContentInfo();
}

} // namespace antiwasm