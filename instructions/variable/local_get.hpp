#ifndef ANTIWASM_LOCAL_GET_HPP
#define ANTIWASM_LOCAL_GET_HPP

#include "instruction.hpp"
#include "leb128.hpp"

namespace antiwasm {
class LocalGet : public Instruction {
  uint32_t localidx;

public:
  explicit LocalGet(const uint8_t *localidx_);
  virtual ~LocalGet() = default;
};
} // namespace antiwasm

#endif // ANTIWASM_LOCAL_GET_HPP
