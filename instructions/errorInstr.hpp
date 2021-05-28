#ifndef ANTIWASM_ERRORINSTR_HPP
#define ANTIWASM_ERRORINSTR_HPP

#include "instruction.hpp"
#include <cstdint>

namespace antiwasm {
class ErrorInstr : public Instruction {
  uint8_t invalidInstrByte;

public:
  explicit ErrorInstr(const uint8_t *instrContent);
  virtual ~ErrorInstr() = default;
};
} // namespace antiwasm

#endif // ANTIWASM_ERRORINSTR_HPP
