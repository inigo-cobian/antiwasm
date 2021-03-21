#include "section.hpp"

Section::Section(SectionId sectionId, int size, uint8_t *content, int initialPos) {
    sectionId_ = sectionId;
    size_ = size;
    content_ = content;
    initialPos_ = initialPos;
}

SectionId Section::getSectionId() {
    return sectionId_;
}

int Section::getSize() {
    return size_;
}

uint8_t *Section::getContent() {
    return content_;
}

int Section::getInitialPos() {
    return initialPos_;
}

void Section::displaySectionInfo() {
    std::cout << std::hex << "ID=" << sectionId_
              << " | start=" << (std::hex) << initialPos_
              << " size=" << (std::hex) << size_ << std::endl;
}
