#ifndef ANTIWASM_LOCAL_SET_HPP
#define ANTIWASM_LOCAL_SET_HPP

#include "instruction.hpp"
#include "leb128.hpp"

namespace antiwasm {
class LocalSet : public Instruction {
  uint32_t localidx;

public:
  explicit LocalSet(const uint8_t *instrContent);
  virtual ~LocalSet() = default;
};
} // namespace antiwasm

#endif // ANTIWASM_LOCAL_SET_HPP
