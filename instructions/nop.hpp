#ifndef ANTIWASM_NOP_HPP
#define ANTIWASM_NOP_HPP

#include "instruction.hpp"

namespace antiwasm {
class NopInstr : public Instruction {
public:
  virtual ~NopInstr() = default;
};

/**
 * Returns No Operation instruction.
 * @return
 */
NopInstr parseNop();
} // namespace antiwasm

#endif // ANTIWASM_NOP_HPP
