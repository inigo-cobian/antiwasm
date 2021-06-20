#ifndef ANTIWASM_ELEMSEC_HPP
#define ANTIWASM_ELEMSEC_HPP

#include "section.hpp"
#include "element.hpp"
#include <vector>

namespace antiwasm {

class ElementSection : public Section {
private:
  std::vector<Element> elementVector;

public:
  /**
   * Contructor.
   * SectionId = SectionId::Element
   * @param size
   * @param content
   * @param initialPos
   */
  ElementSection(int size, uint8_t *content, int initialPos);

  /**
   * Destructor
   */
  ~ElementSection();

  /**
   * Adds a new element to the vector
   * @param element
   */
  void addElement(const Element &element);

  /**
   * Gets the element vector
   * @return elementVector
   */
  std::vector<Element> getElementVector();

  /**
   * Displays the header information for the element section.
   */
  void displaySectionHeaderInfo();

  /**
   * Displays the information of the elemsec
   */
  void displaySectionContentInfo(); // override
};

} // namespace antiwasm

#endif // ANTIWASM_ELEMSEC_HPP
