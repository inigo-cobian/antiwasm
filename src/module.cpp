#include "../includes/module.hpp"

Module::Module(int size) {
    size_ = size;
}

void Module::addSection(Section section) {
    sections_.insert({section.getSectionId(), section});
}

Section Module::getSection(antiwasm::SectionId sectionId) {
    if(sections_.contains(sectionId)) {
        return sections_.at(sectionId);
    }
    else {
        return Section(antiwasm::SectionId::Error, 0, nullptr, 0);
    }
}

int Module::getSize() {
    return size_;
}

bool Module::containsSection(antiwasm::SectionId sectionId) {
    return sections_.contains(sectionId);
}

