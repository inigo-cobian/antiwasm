#ifndef ANTIWASM_BR_TABLE_HPP
#define ANTIWASM_BR_TABLE_HPP

#include "instruction.hpp"
#include "leb128.hpp"
#include <cstdint>
#include <array>

namespace antiwasm {
class BrTableInstr : public Instruction {
  std::vector<uint32_t> labelidxVec;
  uint32_t labelidx;

public:
  explicit BrTableInstr(const uint8_t *instrContent);
  virtual ~BrTableInstr() = default;
};
} // namespace antiwasm

#endif // ANTIWASM_BR_TABLE_HPP
