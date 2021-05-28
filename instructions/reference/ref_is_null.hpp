#ifndef ANTIWASM_REF_IS_NULL_HPP
#define ANTIWASM_REF_IS_NULL_HPP

#include "instruction.hpp"

namespace antiwasm {
class RefIsNull : public Instruction {

public:
  explicit RefIsNull(const uint8_t *instrContent);
  virtual ~RefIsNull() = default;
};
} // namespace antiwasm

#endif // ANTIWASM_REF_IS_NULL_HPP
