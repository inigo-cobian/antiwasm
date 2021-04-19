#include "tablesec.hpp"

namespace antiwasm {

TableSection::TableSection(int size, uint8_t *content, int initialPos)
    : Section(SectionId::Table, size, content, initialPos) {}

TableSection::~TableSection() = default;

void TableSection::addTabletype(Tabletype tabletype) { tabletypeVector.push_back(tabletype); }

vector<Tabletype> TableSection::getTabletypeVector() { return vector<Tabletype>(); }

void TableSection::displaySectionHeaderInfo() {
  cout << "   Table | start=" << hex << initialPos_ << " size=" << hex << size_ << endl;
}

void TableSection::displayTablesecContent() {
  cout << "   Table | start=" << hex << initialPos_ << " size=" << hex << size_
            << " (" << tabletypeVector.size() << ") tabletypes" << endl;

  for (auto tabletype : tabletypeVector) {
    tabletype.displayContentInfo();
  }
}

} // namespace antiwasm
