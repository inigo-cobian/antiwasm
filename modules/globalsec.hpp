#ifndef ANTIWASM_GLOBALSEC_HPP
#define ANTIWASM_GLOBALSEC_HPP

#define BOOST_LOG_DYN_LINK 1

#include "section.hpp"
#include "globaltype.hpp"
#include <boost/log/trivial.hpp>
#include <cstdint>
#include <vector>

namespace antiwasm {

class GlobalSection : public Section {
private:
  std::vector<Globaltype> globaltypeVector;

public:
  /**
   * Contructor.
   * SectionId = SectionId::GlobalId
   * @param size
   * @param content
   * @param initialPos
   */
  GlobalSection(int size, uint8_t *content, int initialPos);

  /**
   * Destructor
   */
  ~GlobalSection();

  /**
   * Adds a new globaltype to the vector
   * @param globaltype
   */
  void addImport(const Globaltype &globaltype);

  /**
   * Gets the globaltype vector
   * @return globaltypeVector
   */
  std::vector<Globaltype> getGlobaltypeVector();

  /**
   * Displays the header information for the global section.
   */
  void displaySectionHeaderInfo();

  /**
   * Displays the information of the globalsec
   */
  void displaySectionContentInfo(); // override
};
} // namespace antiwasm

#endif // ANTIWASM_GLOBALSEC_HPP
