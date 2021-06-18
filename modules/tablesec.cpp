#include "tablesec.hpp"

namespace antiwasm {

TableSection::TableSection(int size, uint8_t *content, int initialPos)
    : Section(SectionId::TableId, size, content, initialPos) {}

TableSection::~TableSection() = default;

void TableSection::addTabletype(Tabletype tabletype) { tabletypeVector.push_back(tabletype); }

std::vector<Tabletype> TableSection::getTabletypeVector() { return tabletypeVector; }

void TableSection::displaySectionHeaderInfo() {
  std::cout << "   Table | start=" << std::hex << initialPos_ << " size=" << std::hex << size_ << std::endl;
}

void TableSection::displaySectionContentInfo() {
  std::cout << "   Table | start=" << std::hex << initialPos_ << " size=" << std::hex << size_ << " ("
            << tabletypeVector.size() << ") tabletypes" << std::endl;

  size_t index = 0;
  for (const auto &tabletype : tabletypeVector) {
    std::stringstream tabletypeAsText;
    tabletypeAsText << "( table $" << index++ << " ";
    if (tabletype.limit.type == limit_min) {
      tabletypeAsText << tabletype.limit.min;
    } else if (tabletype.limit.type == limit_min_max) {
      tabletypeAsText << tabletype.limit.min << " " << tabletype.limit.max;
    }
    tabletypeAsText << " " << getReftypeAsText(tabletype.reftype) << " )\n";
    std::cout << tabletypeAsText.str() << std::endl;
  }
}

} // namespace antiwasm
