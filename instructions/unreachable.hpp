#ifndef ANTIWASM_UNREACHABLE_HPP
#define ANTIWASM_UNREACHABLE_HPP

#include "instruction.hpp"
#include <cstdint>

namespace antiwasm {
class UnreachableInstr : public Instruction {
public:
  explicit UnreachableInstr();
  virtual ~UnreachableInstr() = default;
};

} // namespace antiwasm
#endif // ANTIWASM_UNREACHABLE_HPP
