#ifndef ANTIWASM_BLOCK_HPP
#define ANTIWASM_BLOCK_HPP

#include "instruction.hpp"
#include "instruction_parser.hpp"
#include "blocktype.hpp"
#include <vector>
#include <cstdint>
#include <memory>

namespace antiwasm {
class BlockInstr : public Instruction {
  Blocktype blocktype;
  std::vector<std::unique_ptr<Instruction>> instructionSet;

public:
  explicit BlockInstr(const uint8_t *instrContent);
  virtual ~BlockInstr() = default;
};
} // namespace antiwasm

#endif // ANTIWASM_BLOCK_HPP
