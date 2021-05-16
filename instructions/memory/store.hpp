#ifndef ANTIWASM_STORE_HPP
#define ANTIWASM_STORE_HPP

#include "instruction.hpp"
#include "memarg.hpp"

namespace antiwasm {
class StoreInstr : public Instruction {
  MemArg memArg;

public:
  explicit LoadInstr(const uint8_t *storeInstrContent);
  virtual ~StoreInstr() = default;
};
} // namespace antiwasm


#endif // ANTIWASM_STORE_HPP
