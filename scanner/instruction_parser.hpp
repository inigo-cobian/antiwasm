#ifndef ANTIWASM_INSTRUCTION_PARSER_HPP
#define ANTIWASM_INSTRUCTION_PARSER_HPP

#include "instruction.hpp"
#include "lexems.hpp"
#include "unreachable.hpp"

namespace antiwasm {
Instruction parseInstruction(const uint8_t *instructionContent);
}
#endif // ANTIWASM_INSTRUCTION_PARSER_HPP
