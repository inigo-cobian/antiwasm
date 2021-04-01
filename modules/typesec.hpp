#ifndef ANTIWASM_TYPESEC_HPP
#define ANTIWASM_TYPESEC_HPP

#include <vector>
#include "section.hpp"
#include "../types/functype.hpp"

class TypeSection : public Section {
private:
    std::vector<Functype> functypeVector;
public:
    /**
     * Contructor.
     * SectionId = SectionId::Type
     * @param size
     * @param content
     * @param initialPos
     */
    TypeSection(int size, uint8_t *content, int initialPos);

    /**
     * Destructor
     */
    ~TypeSection();

    /**
     * Adds a new functype to the vector
     * @param functype
     */
    void addFunctype(Functype functype);

    /**
     * Gets the functype vector
     * @return functypeVector
     */
    std::vector<Functype> getFunctypeVector();

};

#endif //ANTIWASM_TYPESEC_HPP
