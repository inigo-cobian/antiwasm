#ifndef ANTIWASM_ELEM_DROP_HPP
#define ANTIWASM_ELEM_DROP_HPP

#include "instruction.hpp"
#include "leb128.hpp"

namespace antiwasm {
class ElemDrop : public Instruction {
  uint32_t tableidx;

public:
  explicit ElemDrop(const uint8_t *instructionContent);
  virtual ~ElemDrop() = default;
};
} // namespace antiwasm

#endif // ANTIWASM_ELEM_DROP_HPP
