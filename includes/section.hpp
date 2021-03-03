#ifndef SECTION_HPP
#define SECTION_HPP

#include "section_index.hpp"

class Section {
    private:
        antiwasm::SectionId sectionId_;
        int size_;
        unsigned char* content_;
        int initialPos_;
    public:
        Section(antiwasm::SectionId sectionId, int size, unsigned char* content, int initialPos);
        ~Section() {}
        Section(Section &section) = delete;
        //Getters
        antiwasm::SectionId getSectionId();
        int getSize();
        unsigned char* getContent();
        int getInitialPos();
};

#endif //SECTION_HPP
