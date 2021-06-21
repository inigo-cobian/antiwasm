#ifndef ANTIWASM_EXPORTSEC_HPP
#define ANTIWASM_EXPORTSEC_HPP

#include "export.hpp"
#include "expression.hpp"
#include "leb128.hpp"
#include "section.hpp"
#include <sstream>
#include <vector>

namespace antiwasm {

class ExportSection : public Section {
private:
  std::vector<Export> exportVector;

public:
  /**
   * Contructor.
   * SectionId = SectionId::Export
   * @param size
   * @param content
   * @param initialPos
   */
  ExportSection(int size, uint8_t *content, int initialPos);

  /**
   * Destructor
   */
  ~ExportSection();

  /**
   * Adds a new export to the vector
   * @param export
   */
  void addExport(const Export &export_);

  /**
   * Gets the export vector
   * @return exportVector
   */
  std::vector<Export> getExportVector();

  /**
   * Displays the header information for the export section.
   */
  void displaySectionHeaderInfo();

  /**
   * Displays the information of the exportsec
   */
  void displaySectionContentInfo(); // override
};

} // namespace antiwasm

#endif // ANTIWASM_EXPORTSEC_HPP
