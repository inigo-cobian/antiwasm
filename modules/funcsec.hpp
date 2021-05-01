#ifndef ANTIWASM_FUNCSEC_HPP
#define ANTIWASM_FUNCSEC_HPP

#include "section.hpp"
#include <cstdint>
#include <sstream>
#include <vector>

namespace antiwasm {
class FuncSection : public Section {
private:
  std::vector<uint32_t> typeidxVector;

public:
  /**
   * Contructor.
   * SectionId = SectionId::FuncId
   * @param size
   * @param content
   * @param initialPos
   */
  FuncSection(int size, uint8_t *content, int initialPos);

  /**
   * Destructor
   */
  ~FuncSection();

  /**
   * Adds a new typeidx to the vector
   * @param typeidx
   */
  void addTypeidx(uint32_t typeidx);

  /**
   * Gets the typeidx vector
   * @return typeidxVector
   */
  std::vector<uint32_t> getTypeidxVector();

  /**
   * Displays the header information for the table section.
   */
  void displaySectionHeaderInfo();

  void displaySectionContentInfo(); // override
};

} // namespace antiwasm

#endif // ANTIWASM_FUNCSEC_HPP
