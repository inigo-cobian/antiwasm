#ifndef ANTIWASM_GLOBAL_GET_HPP
#define ANTIWASM_GLOBAL_GET_HPP

#include "instruction.hpp"
#include "leb128.hpp"

namespace antiwasm {
class GlobalGet : public Instruction {
  uint32_t globalIdx;

public:
  explicit GlobalGet(const uint8_t *globalIdx_);
  virtual ~GlobalGet() = default;
};
} // namespace antiwasm

#endif // ANTIWASM_GLOBAL_GET_HPP
