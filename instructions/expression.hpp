#ifndef ANTIWASM_EXPRESSION_HPP
#define ANTIWASM_EXPRESSION_HPP

#include "contentBlock.hpp"
#include "instruction.hpp"
#include <vector>

namespace antiwasm {
class Expression : public ContentBlock {
private:
  std::vector<Instruction> instructionVector;

public:
  std::vector<Instruction> getInstructionVector();
  void addInstruction(Instruction instr);
};

Expression parseExpression(const uint8_t *expressionContent);

} // namespace antiwasm

#endif // ANTIWASM_EXPRESSION_HPP
