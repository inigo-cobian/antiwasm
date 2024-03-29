#ifndef ANTIWASM_MODULE_HPP
#define ANTIWASM_MODULE_HPP

#include "contentBlock.hpp"
#include "displayable.hpp"
#include "error_manager.hpp"
#include "section.hpp"
#include <map>
#include <memory>
#include <vector>

namespace antiwasm {
class Module : public ContentBlock, Displayable { // TODO check if we should use ContentBlock
private:
  int size_;
  // TODO version
  std::map<const SectionId, Section> sections_;

public:
  /**
   * Constructor
   * @param size
   */
  Module(int size);

  /**
   * Destructor
   */
  ~Module() { /*TODO*/
  }

  /**
   * Returns the size of the file
   * @return the size of the module in bytes
   */
  int getSize();

  /**
   * Adds a section to the module.
   * @param section that has been parsed.
   */
  void addSection(Section section); // TODO check if a return value is interesting

  /**
   * Gets the section with the given Id.
   * @param sectionId
   * @return The existing section. A section with UndefinedSectionId id if it does not exist.
   */
  Section getSection(SectionId sectionId);

  /**
   * Checks if the section with the given Id exists.
   * @param sectionId
   * @return true if the section exists, false if it does not.
   */
  bool containsSection(SectionId sectionId);

  void displayError() override;
  void displayContentInfo() override;
};
} // namespace antiwasm

#endif // ANTIWASM_MODULE_HPP
