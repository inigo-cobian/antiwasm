#include "module.hpp"

namespace antiwasm {

Module::Module(int size) { size_ = size; }

void Module::addSection(std::shared_ptr<Section> section) {
  if(true) {
    std::lock_guard<std::mutex> guard(addSection_mutex);
    std::cout << "mutex" << std::endl;
    sectionMap.insert({section->getSectionId(), std::move(section)});
  }
}

void Module::addSectionHeader(const SectionHeader& sectionHeader) {
  sectionHeaderMap.insert({sectionHeader.id, sectionHeader});
}

std::shared_ptr<Section> Module::getSection(SectionId sectionId) {
  if (sectionMap.contains(sectionId)) {
    return std::move(sectionMap.at(sectionId));
  } else {
    return std::make_shared<Section>(Section(SectionId::UndefinedSectionId, 0, nullptr, 0));
  }
}

int Module::getSize() { return size_; }

bool Module::containsSection(SectionId sectionId) { return sectionMap.contains(sectionId); }

bool Module::containsSectionHeader(SectionId sectionId) { return sectionHeaderMap.contains(sectionId); }

std::map<const SectionId, SectionHeader> Module::getSectionHeaderMap() { return sectionHeaderMap; }

std::map<const SectionId, std::shared_ptr<Section>> Module::getSectionMap() { return sectionMap; }

} // namespace antiwasm