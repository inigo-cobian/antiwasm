#ifndef ANTIWASM_DATASEC_HPP
#define ANTIWASM_DATASEC_HPP

#include "data.hpp"
#include "expression.hpp"
#include "section.hpp"
#include <sstream>
#include <vector>

namespace antiwasm {

class DataSection : public Section {
private:
  std::vector<Data> dataVector;

public:
  /**
   * Contructor.
   * SectionId = SectionId::Data
   * @param size
   * @param content
   * @param initialPos
   */
  DataSection(int size, uint8_t *content, int initialPos);

  /**
   * Destructor
   */
  ~DataSection();

  /**
   * Adds a new data to the vector
   * @param data
   */
  void addData(const Data &data);

  /**
   * Gets the data vector
   * @return dataVector
   */
  std::vector<Data> getDataVector();

  /**
   * Displays the header information for the memory section.
   */
  void displaySectionHeaderInfo();

  /**
   * Displays the information of the datasec
   */
  void displaySectionContentInfo(); // override
};

} // namespace antiwasm

#endif // ANTIWASM_DATASEC_HPP
