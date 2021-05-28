#ifndef ANTIWASM_NUMERICINSTR_HPP
#define ANTIWASM_NUMERICINSTR_HPP

#include "instruction.hpp"

namespace antiwasm {
class NumericInstr : public Instruction {

public:
  explicit NumericInstr(const uint8_t *content);
  virtual ~NumericInstr() = default;
};
} // namespace antiwasm

#endif // ANTIWASM_NUMERICINSTR_HPP
