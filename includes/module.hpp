#ifndef ANTIWASM_MODULE_HPP
#define ANTIWASM_MODULE_HPP

#include <map>
#include "section.hpp"

class Module {
private:
    int size_;
    std::map<const antiwasm::SectionId, Section> sections_;
public:
    Module(int size);

    ~Module() { /*TODO*/ }

    int getSize();

    void addSection(Section section);

    Section getSection(antiwasm::SectionId sectionId);

    bool containsSection(antiwasm::SectionId sectionId);
};

#endif //ANTIWASM_MODULE_HPP
