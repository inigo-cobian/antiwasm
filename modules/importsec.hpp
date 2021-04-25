#ifndef ANTIWASM_IMPORTSEC_HPP
#define ANTIWASM_IMPORTSEC_HPP

#include "import.hpp"
#include "section.hpp"
#include <sstream>
#include <vector>

using namespace std;

namespace antiwasm {

class ImportSection : public Section {
private:
  vector<Import> importVector;

public:
  /**
   * Contructor.
   * SectionId = SectionId::ImportId
   * @param size
   * @param content
   * @param initialPos
   */
  ImportSection(int size, uint8_t *content, int initialPos);

  /**
   * Destructor
   */
  ~ImportSection();

  /**
   * Adds a new import to the vector
   * @param import
   */
  void addImport(const Import &import);

  /**
   * Gets the import vector
   * @return importVector
   */
  vector<Memtype> getImportVector();

  /**
   * Displays the header information for the import section.
   */
  void displaySectionHeaderInfo();

  /**
   * Displays the information of the importsec
   */
  void displaySectionContentInfo(); // override
};
} // namespace antiwasm

#endif // ANTIWASM_IMPORTSEC_HPP
