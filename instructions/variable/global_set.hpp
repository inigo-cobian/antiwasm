#ifndef ANTIWASM_GLOBAL_SET_HPP
#define ANTIWASM_GLOBAL_SET_HPP

#include "instruction.hpp"
#include "leb128.hpp"

namespace antiwasm {
class GlobalSet : public Instruction {
  uint32_t globalIdx;

public:
  explicit GlobalSet(const uint8_t *instrContent);
  virtual ~GlobalSet() = default;
};
} // namespace antiwasm

#endif // ANTIWASM_GLOBAL_SET_HPP
