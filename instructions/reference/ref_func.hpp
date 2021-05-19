#ifndef ANTIWASM_REF_FUNC_HPP
#define ANTIWASM_REF_FUNC_HPP

#include "instruction.hpp"
#include <cstdint>

namespace antiwasm {
class RefFunc : public Instruction {
  uint32_t funcidx;

public:
  explicit RefFunc(const uint8_t *instrContent);
  virtual ~RefFunc() = default;
};
} // namespace antiwasm

#endif // ANTIWASM_REF_FUNC_HPP
