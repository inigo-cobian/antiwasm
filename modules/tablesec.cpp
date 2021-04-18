#include "tablesec.hpp"

namespace antiwasm {

TableSection::TableSection(int size, uint8_t *content, int initialPos)
    : Section(SectionId::Table, size, content, initialPos) {}

TableSection::~TableSection() = default;

void TableSection::addTabletype(Tabletype tabletype) { tabletypeVector.push_back(tabletype); }

std::vector<Tabletype> TableSection::getTabletypeVector() { return std::vector<Tabletype>(); }

void TableSection::displaySectionHeaderInfo() {
  std::cout << "   Table | start=" << (std::hex) << initialPos_ << " size=" << (std::hex) << size_ << std::endl;
}

void TableSection::displayTablesecContent() {
  std::cout << "   Table | start=" << (std::hex) << initialPos_ << " size=" << (std::hex) << size_
            << " (" << tabletypeVector.size() << ") tabletypes" << std::endl;

  for (auto tabletype : tabletypeVector) {
    tabletype.displayContentInfo();
  }
}

} // namespace antiwasm
