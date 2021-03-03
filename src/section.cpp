#include "../includes/section.hpp"

antiwasm::SectionId sectionId_;

antiwasm::SectionId getSectionId() {
    return sectionId_;
}

antiwasm::SectionId Section::getSectionId() {
    return antiwasm::Type;
}
