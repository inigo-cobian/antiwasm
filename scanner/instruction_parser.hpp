#ifndef ANTIWASM_INSTRUCTION_PARSER_HPP
#define ANTIWASM_INSTRUCTION_PARSER_HPP

#include "instruction.hpp"
#include "lexems.hpp"
#include "nop.hpp"
#include "unreachable.hpp"
#include "i32_const.hpp"
#include "i64_const.hpp"
#include "f32_const.hpp"
#include "f64_const.hpp"

namespace antiwasm {
Instruction *parseInstruction(const uint8_t *instructionContent);
}
#endif // ANTIWASM_INSTRUCTION_PARSER_HPP
