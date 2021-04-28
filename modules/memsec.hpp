#ifndef ANTIWASM_MEMSEC_HPP
#define ANTIWASM_MEMSEC_HPP

#include "memtype.hpp"
#include "section.hpp"
#include <sstream>
#include <vector>

using namespace std;

namespace antiwasm {

class MemorySection : public Section {
private:
  vector<Memtype> memtypeVector;

public:
  /**
   * Contructor.
   * SectionId = SectionId::MemoryId
   * @param size
   * @param content
   * @param initialPos
   */
  MemorySection(int size, uint8_t *content, int initialPos);

  /**
   * Destructor
   */
  ~MemorySection();

  /**
   * Adds a new memtype to the vector
   * @param memtype
   */
  void addMemtype(Memtype memtype);

  /**
   * Gets the memtype vector
   * @return memtypeVector
   */
  vector<Memtype> getMemtypeVector();

  /**
   * Displays the header information for the memory section.
   */
  void displaySectionHeaderInfo();

  /**
   * Displays the information of the memsec
   */
  void displaySectionContentInfo(); // override
};

} // namespace antiwasm

#endif // ANTIWASM_MEMSEC_HPP
