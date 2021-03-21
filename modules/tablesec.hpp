#ifndef ANTIWASM_TABLESEC_HPP
#define ANTIWASM_TABLESEC_HPP

#include <vector>
#include "section.hpp"
#include "../types/reftype.hpp"
#include "../types/tabletype.hpp"

class TableSection : public Section {
private:
    std::vector<Tabletype> tabletypes;
public:
    TableSection(SectionId sectionId, int size, uint8_t *content, int initialPos);

    ~TableSection();

    void addTabletype(Tabletype tabletype);

    std::vector<Tabletype> getTabletypeVector();
};


#endif //ANTIWASM_TABLESEC_HPP
