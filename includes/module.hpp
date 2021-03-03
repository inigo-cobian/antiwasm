#ifndef ANTIWASM_MODULE_HPP
#define ANTIWASM_MODULE_HPP

#include <map>
#include "section.hpp"
#include "section_index.hpp"

class Module {
    private:
        std::map<const antiwasm::SectionId, Section> sections_;
        int size_;
    public:
        Module(int size) {}
        ~Module() { /*TODO*/ }
        Module(Module &module) = delete;
        void addSection(Section section);
        Section getSection(antiwasm::SectionId sectionId);
};

#endif //ANTIWASM_MODULE_HPP
