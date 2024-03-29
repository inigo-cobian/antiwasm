#ifndef ANTIWASM_TABLESEC_HPP
#define ANTIWASM_TABLESEC_HPP

#include "reftype.hpp"
#include "section.hpp"
#include "tabletype.hpp"
#include <sstream>
#include <vector>

namespace antiwasm {

class TableSection : public Section {
private:
  std::vector<Tabletype> tabletypeVector;

public:
  /**
   * Contructor.
   * SectionId = SectionId::Table
   * @param size
   * @param content
   * @param initialPos
   */
  TableSection(int size, uint8_t *content, int initialPos);

  /**
   * Destructor
   */
  ~TableSection();

  /**
   * Adds a new tabletype to the vector
   * @param tabletype
   */
  void addTabletype(Tabletype tabletype);

  /**
   * Gets the tabletype vector
   * @return tabletypeVector
   */
  std::vector<Tabletype> getTabletypeVector();

  /**
   * Displays the header information for the table section.
   */
  void displaySectionHeaderInfo();

  void displaySectionContentInfo(); // override
};

} // namespace antiwasm
#endif // ANTIWASM_TABLESEC_HPP
