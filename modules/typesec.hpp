#ifndef ANTIWASM_TYPESEC_HPP
#define ANTIWASM_TYPESEC_HPP

#include "functype.hpp"
#include "section.hpp"
#include <sstream>
#include <vector>

namespace antiwasm {

class TypeSection : public Section {
private:
  std::vector<Functype> functypeVector;

  std::string getParamAsText(const Functype &functype) const;
  std::string getResultAsText(const Functype &functype) const;

public:
  /**
   * Contructor.
   * SectionId = SectionId::TypeId
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
  void displaySectionHeaderInfo() override;

  void displaySectionContentInfo(); // override
};

} // namespace antiwasm

#endif // ANTIWASM_TYPESEC_HPP
