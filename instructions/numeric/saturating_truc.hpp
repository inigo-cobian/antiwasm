#ifndef ANTIWASM_SATURATING_TRUC_HPP
#define ANTIWASM_SATURATING_TRUC_HPP

#include "instruction.hpp"

namespace antiwasm {
class SaturatingTrunc : public Instruction {

public:
  explicit SaturatingTrunc(const uint8_t *instrContent);
  virtual ~SaturatingTrunc() = default;
};
} // namespace antiwasm

#endif // ANTIWASM_SATURATING_TRUC_HPP
