#ifndef ANTIWASM_UNREACHABLE_HPP
#define ANTIWASM_UNREACHABLE_HPP

#include "instruction.hpp"
#include <cstdint>

namespace antiwasm {
class UnreachableInstr : public Instruction {
public:
  virtual ~UnreachableInstr() = default;
};

/**
 * Returns an unreachable instruction.
 * @return
 */
UnreachableInstr parseUnreachable();
} // namespace antiwasm
#endif // ANTIWASM_UNREACHABLE_HPP
