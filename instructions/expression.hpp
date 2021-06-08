#ifndef ANTIWASM_EXPRESSION_HPP
#define ANTIWASM_EXPRESSION_HPP

#include "contentBlock.hpp"
#include "end.hpp"
#include "instruction.hpp"
#include "instruction_parser.hpp"
#include <vector>

namespace antiwasm {
class Expression : public ContentBlock {
private:
  std::vector<Instruction> instructionVector;

public:
  std::vector<Instruction> getInstructionVector();
  void addInstruction(const Instruction &instr);
};

Expression parseExpression(const uint8_t *expressionContent);

} // namespace antiwasm

#endif // ANTIWASM_EXPRESSION_HPP
