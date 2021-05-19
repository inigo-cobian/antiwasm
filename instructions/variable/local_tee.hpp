#ifndef ANTIWASM_LOCAL_TEE_HPP
#define ANTIWASM_LOCAL_TEE_HPP

#include "instruction.hpp"
#include "leb128.hpp"

namespace antiwasm {
class LocalTee : public Instruction {
  uint32_t localidx;

public:
  explicit LocalTee(const uint8_t *instrContent);
  virtual ~LocalTee() = default;
};
} // namespace antiwasm

#endif // ANTIWASM_LOCAL_TEE_HPP
