#ifndef ANTIWASM_I32CONST_HPP
#define ANTIWASM_I32CONST_HPP

#include "instruction.hpp"
#include "leb128.hpp"

namespace antiwasm {
class I32Const : public Instruction {
  int32_t constant;

public:
  explicit I32Const(const uint8_t *instrContent);
  virtual ~I32Const() = default;
};
} // namespace antiwasm

#endif // ANTIWASM_I32CONST_HPP
