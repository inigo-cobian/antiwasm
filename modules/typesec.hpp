#ifndef ANTIWASM_TYPESEC_HPP
#define ANTIWASM_TYPESEC_HPP

#include <vector>
#include "../types/functype.hpp"

class TypeSection : public Section {
private:
    std::vector<Functype> functypeVector;
public:
    TypeSection(SectionId sectionId, int size, uint8_t *content, int initialPos);

    ~TypeSection();

    void addFunctype(Functype functype);

    std::vector<Functype> getFunctypeVector();

};

#endif //ANTIWASM_TYPESEC_HPP
