#ifndef SECTION_HPP
#define SECTION_HPP

#include "contentBlock.hpp"
#include "displayable.hpp"
#include "error_manager.hpp"
#include <iostream>
#include <memory>

using namespace std;

namespace antiwasm {

enum SectionId {
  Custom = 0x00,
  Type = 0x01,
  Import = 0x02,
  Function = 0x03,
  Table = 0x04,
  Memory = 0x05,
  Global = 0x06,
  Export = 0x07,
  Start = 0x08,
  Element = 0x09,
  Code = 0x0A,
  Data = 0x0B,
  Error = 0xFF
};

class Section : public ContentBlock, Displayable { // TODO make virtual
protected:
  SectionId sectionId_;
  int size_;
  uint8_t *content_;
  int initialPos_;

public:
  /**
   * Constructor
   * @param sectionId
   * @param size
   * @param content
   * @param initialPos
   */
  Section(SectionId sectionId, int size, uint8_t *content, int initialPos);

  /**
   * Destructor
   */
  ~Section() = default;

  /**
   * Gets the Id of the section.
   * @return The section Id.
   */
  SectionId getSectionId();

  /**
   * Gets the size of the section in bytes.
   * @return The size of the section.
   */
  int getSize() const;

  /**
   * Gets the content of the section as bytes.
   * @return The content of the section as bytes
   */
  uint8_t *getContent();

  /**
   * Gets the initial position of the section inside the module.
   * @return The initial position inside the module.
   */
  int getInitialPos() const;

  /**
   * Displays the general information for the section.
   */
  virtual void displaySectionHeaderInfo();

  void displayError() override;

  void displayContentInfo() override;

  void displaySectionContentInfo();
};

} // namespace antiwasm
#endif // SECTION_HPP
