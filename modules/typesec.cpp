#include "typesec.hpp"

TypeSection::TypeSection(int size, uint8_t *content, int initialPos) :
        Section(SectionId::Type, size, content, initialPos) {

}

TypeSection::~TypeSection() {

}

void TypeSection::addFunctype(Functype functype) {

}

std::vector<Functype> TypeSection::getFunctypeVector() {
    return functypeVector;
}

void TypeSection::displaySectionHeaderInfo() {
    std::cout << "    Type | start=" << (std::hex) << initialPos_
              << " size=" << (std::hex) << size_ << std::endl;
}
