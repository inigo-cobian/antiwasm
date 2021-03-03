#ifndef ANTIWASM_SECTION_HPP
#define ANTIWASM_SECTION_HPP

#include "section_index.hpp"

class Section {
    private:
        antiwasm::SectionId sectionId_;
    public:
        Section(antiwasm::SectionId sectionId) {sectionId_ = sectionId;}
        ~Section() {}
        Section(Section &section) = delete;
        antiwasm::SectionId getSectionId();
};

#endif //ANTIWASM_SECTION_HPP
