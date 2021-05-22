#ifndef ANTIWASM_DATA_DROP_HPP
#define ANTIWASM_DATA_DROP_HPP

#include "instruction.hpp"
#include "leb128.hpp"

namespace antiwasm {
class DataDrop : public Instruction {
  uint32_t dataidx;

public:
  explicit DataDrop(const uint8_t *instrContent);
  virtual ~DataDrop() = default;
};
} // namespace antiwasm

#endif // ANTIWASM_DATA_DROP_HPP
