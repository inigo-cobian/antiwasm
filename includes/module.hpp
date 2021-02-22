#ifndef ANTIWASM_MODULE_HPP
#define ANTIWASM_MODULE_HPP

#include <map>
#include "section.hpp"
#include "section_index.hpp"

namespace antiwasm {

class Module {
    private:
        std::map<const SectionId, Section> sections_;
    public:
        Module() {}
        ~Module() { /*TODO*/ }
        Module(Module &module) = delete;
        void addSection(Section section);
        Section getSection(SectionId sectionId);
};

}

#endif //ANTIWASM_MODULE_HPP
