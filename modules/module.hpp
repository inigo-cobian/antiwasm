#ifndef ANTIWASM_MODULE_HPP
#define ANTIWASM_MODULE_HPP

#include "contentBlock.hpp"
#include "error_manager.hpp"
#include "section.hpp"
#include <map>
#include <memory>
#include <vector>

namespace antiwasm {
struct SectionHeader {
  SectionId id;
  size_t pos;
  size_t size;
  std::shared_ptr<uint8_t> content;
};

class Module : public ContentBlock {
private:
  int size_;
  std::map<const SectionId, SectionHeader> sectionHeaderMap;
  std::map<const SectionId, Section> sectionMap;
  // TODO version

public:
  /**
   * Constructor
   * @param size
   */
  explicit Module(int size);

  /**
   * Destructor
   */
  ~Module() = default;

  /**
   * Returns the size of the file
   * @return the size of the module in bytes
   */
  int getSize();

  /**
   * Adds a section to the module.
   * @param section that has been parsed.
   */
  void addSection(Section section);

  /**
   * Adds a sectionHeader to the module.
   * @param sectionHeader that has been detected.
   */
  void addSectionHeader(const SectionHeader& sectionHeader);

  /**
   * Gets the section with the given Id.
   * @param sectionId
   * @return The existing section. A section with UndefinedSectionId id if it does not exist.
   */
  Section getSection(SectionId sectionId);

  /**
   * Checks if the section with the given Id exists as a full section.
   * @param sectionId
   * @return true if the section exists, false if it does not.
   */
  bool containsSection(SectionId sectionId);

  /**
   * Checks if the section with the given Id exists as a section header.
   * @param sectionId
   * @return true if the section exists, false if it does not.
   */
  bool containsSectionHeader(SectionId sectionId);

  std::map<const SectionId, SectionHeader> getSectionHeaderMap();
};
} // namespace antiwasm

#endif // ANTIWASM_MODULE_HPP
