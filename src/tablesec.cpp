#include "../includes/tablesec.hpp"

TableSection::TableSection(antiwasm::SectionId sectionId, int size, unsigned char *content, int initialPos) : Section(
        sectionId, size, content, initialPos) {

}

TableSection::~TableSection() {

}

void TableSection::addTabletype(Tabletype *tabletype) {
    tabletypes.add(tabletype);
    free(tabletype);
}

std::vector<Tabletype> TableSection::getTabletypeVector() {
    return std::vector<Tabletype>();
}
