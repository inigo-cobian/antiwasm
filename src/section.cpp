#include "../includes/section.hpp"

Section::Section(antiwasm::SectionId sectionId, int size, unsigned char *content, int initialPos) {
    sectionId_ = sectionId;
    size_ = size;
    content_ = content;
    initialPos_ = initialPos;
}

antiwasm::SectionId Section::getSectionId() {
    return sectionId_;
}

int Section::getSize() {
    return size_;
}

unsigned char *Section::getContent() {
    return content_;
}

int Section::getInitialPos() {
    return initialPos_;
}
