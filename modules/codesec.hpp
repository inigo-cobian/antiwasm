#ifndef ANTIWASM_CODESEC_HPP
#define ANTIWASM_CODESEC_HPP

#include "code.hpp"
#include "expression.hpp"
#include "leb128.hpp"
#include "section.hpp"
#include <sstream>
#include <vector>

namespace antiwasm {

class CodeSection : public Section {
private:
  std::vector<Code> codeVector;

public:
  /**
   * Contructor.
   * SectionId = SectionId::Code
   * @param size
   * @param content
   * @param initialPos
   */
  CodeSection(int size, uint8_t *content, int initialPos);

  /**
   * Destructor
   */
  ~CodeSection();

  /**
   * Adds a new code to the vector
   * @param code
   */
  void addCode(const Code &code);

  /**
   * Gets the code vector
   * @return codeVector
   */
  std::vector<Code> getCodeVector();

  /**
   * Displays the header information for the code section.
   */
  void displaySectionHeaderInfo();

  /**
   * Displays the information of the codesec
   */
  void displaySectionContentInfo(); // override
};

} // namespace antiwasm

#endif // ANTIWASM_CODESEC_HPP
