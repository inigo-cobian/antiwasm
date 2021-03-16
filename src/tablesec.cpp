#include "../includes/tablesec.hpp"

TableSection::TableSection(antiwasm::SectionId sectionId, int size, unsigned char *content, int initialPos) : Section(
        sectionId, size, content, initialPos) {

}

TableSection::~TableSection() {

}

void TableSection::addTabletype(Tabletype *tabletypes) {

}

Memtype *TableSection::getTabletype() {
    return nullptr;
}

std::vector<Tabletype> TableSection::getTabletypeVector() {
    return std::vector<Tabletype>();
}
