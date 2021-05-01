#include "section.hpp"

using namespace std;
namespace antiwasm {

Section::Section(SectionId sectionId, int size, uint8_t *content, int initialPos) {
  sectionId_ = sectionId;
  size_ = size;
  content_ = content;
  initialPos_ = initialPos;
}

SectionId Section::getSectionId() { return sectionId_; }

int Section::getSize() const { return size_; }

uint8_t *Section::getContent() { return content_; }

int Section::getInitialPos() const { return initialPos_; }

void Section::displaySectionHeaderInfo() {
  cout << hex << "ID=" << sectionId_ << " | start=" << hex << initialPos_ << " size=" << hex << size_ << endl;
}
void Section::displayError() {
  // TODO virtualize
}

void Section::displayContentInfo() {
  // TODO virtualize
}
void Section::displaySectionContentInfo() {
  // TODO virtualize
}

} // namespace antiwasm