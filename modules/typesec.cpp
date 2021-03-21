#include "typesec.hpp"

TypeSection::TypeSection(SectionId sectionId, int size, uint8_t *content, int initialPos) :
        Section(sectionId, size, content, initialPos) {

}

TypeSection::~TypeSection() {

}

void TypeSection::addFunctype(Functype functype) {

}

std::vector <Functype> TypeSection::getFunctypeVector() {
    return functypeVector;
}
