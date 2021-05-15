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
 * @param content
 * @return
 */
UnreachableInstr parseUnreachable(const uint8_t *content);
} // namespace antiwasm
#endif // ANTIWASM_UNREACHABLE_HPP
