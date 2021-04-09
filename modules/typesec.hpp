#ifndef ANTIWASM_TYPESEC_HPP
#define ANTIWASM_TYPESEC_HPP

#include "../types/functype.hpp"
#include "section.hpp"
#include <vector>

class TypeSection : public Section {
private:
  std::vector<Functype> functypeVector;

public:
  /**
   * Contructor.
   * SectionId = SectionId::Type
   * @param size
   * @param content
   * @param initialPos
   */
  TypeSection(int size, uint8_t *content, int initialPos);

  /**
   * Destructor
   */
  ~TypeSection();

  /**
   * Adds a new functype to the vector
   * @param functype
   */
  void addFunctype(Functype functype);

  /**
   * Gets the functype vector
   * @return functypeVector
   */
  std::vector<Functype> getFunctypeVector();

  /**
   * Displays the header information for the type section.
   */
  void displaySectionHeaderInfo();

  void displayTypesecContent();
};

#endif // ANTIWASM_TYPESEC_HPP
