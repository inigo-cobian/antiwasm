#ifndef ANTIWASM_F32CONST_HPP
#define ANTIWASM_F32CONST_HPP

#include "float_parser.hpp"
#include "instruction.hpp"

namespace antiwasm {
class F32Const : public Instruction {
  float constant;

public:
  explicit F32Const(const uint8_t *instrContent);
  virtual ~F32Const() = default;
};
} // namespace antiwasm

#endif // ANTIWASM_F32CONST_HPP
