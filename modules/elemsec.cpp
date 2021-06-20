#include "elemsec.hpp"

namespace antiwasm {

ElementSection::ElementSection(int size, uint8_t *content, int initialPos)
    : Section(SectionId::ElementId, size, content, initialPos) {
  BOOST_LOG_TRIVIAL(debug) << "[elemsec] Creating a Element Section";
}

ElementSection::~ElementSection() = default;

void ElementSection::addElement(const Element &element) {
  BOOST_LOG_TRIVIAL(trace) << "[elemsec] Adding a new elem to the vector at pos [" << elementVector.size() << "]";
  elementVector.push_back(element);
}

std::vector<Element> ElementSection::getElementVector() { return elementVector; }

void ElementSection::displaySectionHeaderInfo() {
  std::cout << " Element | start=" << std::hex << initialPos_ << " size=" << std::hex << size_ << std::endl;
}

void ElementSection::displaySectionContentInfo() {
  std::cout << " Element | start=" << std::hex << initialPos_ << " size=" << std::hex << size_ << std::endl;

  size_t index = 0;
  std::for_each(elementVector.begin(), elementVector.end(), [index](const Element &element) mutable {
    std::cout << element.getAsText(index) << std::endl;
    index++;
  });
}
}