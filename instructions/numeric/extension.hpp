#ifndef ANTIWASM_EXTENSION_HPP
#define ANTIWASM_EXTENSION_HPP

#include "instruction.hpp"

namespace antiwasm {
class ExtensionInstr : public Instruction {

public:
  explicit ExtensionInstr(const uint8_t *content);
  virtual ~ExtensionInstr() = default;
};
} // namespace antiwasm

#endif // ANTIWASM_EXTENSION_HPP
