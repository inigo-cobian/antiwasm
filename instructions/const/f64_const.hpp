#ifndef ANTIWASM_F64CONST_HPP
#define ANTIWASM_F64CONST_HPP

#include "instruction.hpp"
#include "float_parser.hpp"

namespace antiwasm {
class F64Const : public Instruction {
  double constant;

public:
  explicit F64Const(const uint8_t *f64Const);
  virtual ~F64Const() = default;
};
} // namespace antiwasm

#endif // ANTIWASM_F64CONST_HPP
