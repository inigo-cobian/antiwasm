#include "tablesec.hpp"

TableSection::TableSection(int size, uint8_t *content, int initialPos)
        : Section(SectionId::Table, size, content, initialPos) {

}

TableSection::~TableSection() {

}

void TableSection::addTabletype(Tabletype tabletype) {
    tabletypeVector.push_back(tabletype);
}

std::vector<Tabletype> TableSection::getTabletypeVector() {
    return std::vector<Tabletype>();
}
