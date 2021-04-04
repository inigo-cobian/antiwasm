#include "typesec.hpp"

TypeSection::TypeSection(int size, uint8_t *content, int initialPos) :
        Section(SectionId::Type, size, content, initialPos) {

}

TypeSection::~TypeSection() {

}

void TypeSection::addFunctype(Functype functype) {
    functypeVector.push_back(functype);
}

std::vector<Functype> TypeSection::getFunctypeVector() {
    return functypeVector;
}

void TypeSection::displaySectionHeaderInfo() {
    std::cout << "    Type | start=" << (std::hex) << initialPos_
              << " size=" << (std::hex) << size_ << std::endl;
}

void TypeSection::displayTypesecContent() {
    std::cout << "    Type | start=" << (std::hex) << initialPos_
              << " size=" << (std::hex) << size_
              << " (" << functypeVector.size() << ") functypes" << std::endl;

    for (auto functype : functypeVector) {
        antiwasm::displayFunctype(functype);
    }
}