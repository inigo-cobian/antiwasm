#ifndef ANTIWASM_F32CONST_HPP
#define ANTIWASM_F32CONST_HPP

#include "instruction.hpp"
#include "float_parser.hpp"

namespace antiwasm {
class F32Const : public Instruction {
  float constant;

public:
  explicit F32Const(const uint8_t *f32Const);
  virtual ~F32Const() = default;
};
} // namespace antiwasm

#endif // ANTIWASM_F32CONST_HPP
