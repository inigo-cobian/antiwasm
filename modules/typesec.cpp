#include "typesec.hpp"

namespace antiwasm {

TypeSection::TypeSection(int size, uint8_t *content, int initialPos)
    : Section(SectionId::Type, size, content, initialPos) {}

TypeSection::~TypeSection() {}

void TypeSection::addFunctype(Functype functype) { functypeVector.push_back(functype); }

vector<Functype> TypeSection::getFunctypeVector() { return functypeVector; }

void TypeSection::displaySectionHeaderInfo() {
  cout << "    Type | start=" << hex << initialPos_ << " size=" << hex << size_ << endl;
}

void TypeSection::displayTypesecContent() {
  cout << "    Type | start=" << hex << initialPos_ << " size=" << hex << size_
            << " (" << functypeVector.size() << ") functypes" << endl;

  for (const auto &functype : functypeVector) {
    functype.displayContentBytes();
  }
}

} // namespace antiwasm