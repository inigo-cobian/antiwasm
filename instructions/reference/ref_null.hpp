#ifndef ANTIWASM_REF_NULL_HPP
#define ANTIWASM_REF_NULL_HPP

#include "instruction.hpp"
#include "reftype.hpp"

namespace antiwasm {
class RefNull : public Instruction {
  Reftype reftype;

public:
  explicit RefNull(const uint8_t *instrContent);
  virtual ~RefNull() = default;
};
} // namespace antiwasm

#endif // ANTIWASM_REF_NULL_HPP
