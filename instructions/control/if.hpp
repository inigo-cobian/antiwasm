#ifndef ANTIWASM_IF_HPP
#define ANTIWASM_IF_HPP

#include "instruction.hpp"
#include "instruction_parser.hpp"
#include "blocktype.hpp"
#include <vector>
#include <cstdint>
#include <memory>

namespace antiwasm {
class IfInstr : public Instruction {
  Blocktype blocktype;
  std::vector<std::unique_ptr<Instruction>> instructionSet;

public:
  explicit IfInstr(const uint8_t *instrContent);
  virtual ~IfInstr() = default;
};
} // namespace antiwasm

#endif // ANTIWASM_IF_HPP
