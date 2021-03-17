#include "tablesec.hpp"

TableSection::TableSection(SectionId sectionId, int size, unsigned char *content, int initialPos)
        : Section(sectionId, size, content, initialPos) {

}

TableSection::~TableSection() {

}

void TableSection::addTabletype(Tabletype tabletype) {
    tabletypes.push_back(tabletype);
}

std::vector<Tabletype> TableSection::getTabletypeVector() {
    return std::vector<Tabletype>();
}
