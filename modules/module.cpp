#include "module.hpp"

namespace antiwasm {

Module::Module(int size) { size_ = size; }

void Module::addSection(Section section) { sectionMap.insert({section.getSectionId(), section}); }

void Module::addSectionHeader(const SectionHeader& sectionHeader) {
  sectionHeaderMap.insert({sectionHeader.id, sectionHeader});
}

Section Module::getSection(SectionId sectionId) {
  if (sectionMap.contains(sectionId)) {
    return sectionMap.at(sectionId);
  } else {
    return Section(SectionId::UndefinedSectionId, 0, nullptr, 0);
  }
}

int Module::getSize() { return size_; }

bool Module::containsSection(SectionId sectionId) { return sectionMap.contains(sectionId); }

bool Module::containsSectionHeader(SectionId sectionId) { return sectionHeaderMap.contains(sectionId); }

std::map<const SectionId, SectionHeader> Module::getSectionHeaderMap() { return sectionHeaderMap; }

} // namespace antiwasm