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

void TableSection::displaySectionContentInfo() {
  cout << "   Table | start=" << hex << initialPos_ << " size=" << hex << size_
       << " (" << tabletypeVector.size() << ") tabletypes" << endl;

  size_t index = 0;
  for (const auto& tabletype : tabletypeVector) {
    stringstream tabletypeAsText;
    tabletypeAsText << "( table $" << index++ << " ";
    if(tabletype.limit.type == limit_min) {
      tabletypeAsText << tabletype.limit.min;
    } else if (tabletype.limit.type == limit_min_max) {
      tabletypeAsText << tabletype.limit.min << " " << tabletype.limit.max;
    }
    tabletypeAsText << " " << getReftypeAsText(tabletype.reftype) << " )\n";
    cout << tabletypeAsText.str() << endl;
  }
}

} // namespace antiwasm
