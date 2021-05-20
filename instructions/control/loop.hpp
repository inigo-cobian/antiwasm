#ifndef ANTIWASM_LOOP_HPP
#define ANTIWASM_LOOP_HPP

#include "instruction.hpp"
#include "instruction_parser.hpp"
#include "blocktype.hpp"
#include <vector>
#include <cstdint>
#include <memory>

namespace antiwasm {
class LoopInstr : public Instruction {
  Blocktype blocktype;
  std::vector<std::unique_ptr<Instruction>> instructionSet;

public:
  explicit LoopInstr(const uint8_t *instrContent);
  virtual ~LoopInstr() = default;
};
} // namespace antiwasm

#endif // ANTIWASM_LOOP_HPP
