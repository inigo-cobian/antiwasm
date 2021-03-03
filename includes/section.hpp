#ifndef ANTIWASM_SECTION_HPP
#define ANTIWASM_SECTION_HPP

#include "section_index.hpp"

class Section {
    private:
        antiwasm::SectionId sectionId_;
        int initialPos_;
        int size_;
        unsigned char* content_;
    public:
        Section(antiwasm::SectionId sectionId, unsigned char* content) {sectionId_ = sectionId, content_ = content;}
        ~Section() {}
        Section(Section &section) = delete;
        antiwasm::SectionId getSectionId();
};

#endif //ANTIWASM_SECTION_HPP
