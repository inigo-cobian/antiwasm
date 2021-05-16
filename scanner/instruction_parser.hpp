#ifndef ANTIWASM_INSTRUCTION_PARSER_HPP
#define ANTIWASM_INSTRUCTION_PARSER_HPP

#include "const/f32_const.hpp"
#include "const/f64_const.hpp"
#include "const/i32_const.hpp"
#include "const/i64_const.hpp"
#include "instruction.hpp"
#include "lexems.hpp"
#include "nop.hpp"
#include "unreachable.hpp"
#include "variable/global_get.hpp"
#include "variable/global_set.hpp"
#include "variable/local_get.hpp"
#include "variable/local_set.hpp"
#include "variable/local_tee.hpp"
#include "memory/load/i32_load.hpp"
#include "memory/load/i64_load.hpp"
#include "memory/load/f32_load.hpp"
#include "memory/load/f64_load.hpp"
#include "memory/load/i32_load_8s.hpp"
#include "memory/load/i32_load_8u.hpp"
#include <memory>

namespace antiwasm {
std::unique_ptr<Instruction> parseInstruction(const uint8_t *instructionContent);
}
#endif // ANTIWASM_INSTRUCTION_PARSER_HPP
