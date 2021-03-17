#ifndef ANTIWASM_TABLESEC_HPP
#define ANTIWASM_TABLESEC_HPP

#include <vector>
#include "section.hpp"
#include "reftype.hpp"
#include "tabletype.hpp"

class TableSection : public Section {
private:
    std::vector<Tabletype> tabletypes;
public:
    TableSection(antiwasm::SectionId sectionId, int size, unsigned char *content, int initialPos);

    ~TableSection();

    void addTabletype(Tabletype tabletype);

    std::vector<Tabletype> getTabletypeVector();
};


#endif //ANTIWASM_TABLESEC_HPP
