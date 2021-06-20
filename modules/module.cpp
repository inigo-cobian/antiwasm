#include "module.hpp"

namespace antiwasm {

Module::Module(int size) { size_ = size; }

void Module::addSection(Section section) { sections_.insert({section.getSectionId(), section}); }

Section Module::getSection(SectionId sectionId) {
  if (sections_.contains(sectionId)) {
    return sections_.at(sectionId);
  } else {
    return Section(SectionId::UndefinedSectionId, 0, nullptr, 0);
  }
}

int Module::getSize() { return size_; }

bool Module::containsSection(SectionId sectionId) { return sections_.contains(sectionId); }

} // namespace antiwasm