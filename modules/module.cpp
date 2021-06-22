#include "module.hpp"

namespace antiwasm {

Module::Module(int size) { size_ = size; }

void Module::addSection(Section section) { sectionMap.insert({section.getSectionId(), section}); }

Section Module::getSection(SectionId sectionId) {
  if (sectionMap.contains(sectionId)) {
    return sectionMap.at(sectionId);
  } else {
    return Section(SectionId::UndefinedSectionId, 0, nullptr, 0);
  }
}

int Module::getSize() { return size_; }

bool Module::containsSection(SectionId sectionId) { return sectionMap.contains(sectionId); }

} // namespace antiwasm