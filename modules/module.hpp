#ifndef ANTIWASM_MODULE_HPP
#define ANTIWASM_MODULE_HPP

#include "contentBlock.hpp"
#include "error_manager.hpp"
#include "section.hpp"
#include "sectionHeader.hpp"
#include <map>
#include <memory>
#include <mutex>
#include <vector>

namespace antiwasm {
class Module : public ContentBlock {
private:
  int size_;
  std::map<const SectionId, SectionHeader> sectionHeaderMap;
  std::map<const SectionId, std::shared_ptr<Section>> sectionMap;
  std::mutex addSection_mutex;
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
  void addSection(std::shared_ptr<Section> section);

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
  std::shared_ptr<Section> getSection(SectionId sectionId);

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

  std::map<const SectionId, std::shared_ptr<Section>> getSectionMap();
};
} // namespace antiwasm

#endif // ANTIWASM_MODULE_HPP