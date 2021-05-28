#ifndef ANTIWASM_ELSE_HPP
#define ANTIWASM_ELSE_HPP

#include "blocktype.hpp"
#include "instruction.hpp"
#include "instruction_parser.hpp"
#include <cstdint>
#include <memory>
#include <vector>

namespace antiwasm {
class ElseInstr : public Instruction {
  Blocktype blocktype;
  std::vector<std::unique_ptr<Instruction>> instructionSet;

public:
  explicit ElseInstr(const uint8_t *instrContent);
  virtual ~ElseInstr() = default;
};
} // namespace antiwasm

#endif // ANTIWASM_ELSE_HPP
