#ifndef SECTION_HPP
#define SECTION_HPP

#include "contentBlock.hpp"
#include "displayable.hpp"
#include "error_manager.hpp"
#include <iostream>
#include <memory>

namespace antiwasm {

enum SectionId : uint8_t {
  CustomId = 0x00,
  TypeId = 0x01,
  ImportId = 0x02,
  FunctionId = 0x03,
  TableId = 0x04,
  MemoryId = 0x05,
  GlobalId = 0x06,
  ExportId = 0x07,
  StartId = 0x08,
  ElementId = 0x09,
  CodeId = 0x0A,
  DataId = 0x0B,
  DataCountId = 0x0C,
  ErrorId = 0xFF
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
