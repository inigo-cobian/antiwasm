#ifndef ANTIWASM_INSTRUCTION_PARSER_HPP
#define ANTIWASM_INSTRUCTION_PARSER_HPP

#include "instruction.hpp"
#include "lexems.hpp"
#include "memory/data_drop.hpp"
#include "memory/load.hpp"
#include "memory/memory_copy.hpp"
#include "memory/memory_fill.hpp"
#include "memory/memory_grow.hpp"
#include "memory/memory_init.hpp"
#include "memory/memory_size.hpp"
#include "memory/store.hpp"
#include "nop.hpp"
#include "numeric/f32_const.hpp"
#include "numeric/f64_const.hpp"
#include "numeric/i32_const.hpp"
#include "numeric/i64_const.hpp"
#include "numeric/numericInstr.hpp"
#include "numeric/saturating_truc.hpp"
#include "unreachable.hpp"
#include "variable/global_get.hpp"
#include "variable/global_set.hpp"
#include "variable/local_get.hpp"
#include "variable/local_set.hpp"
#include "variable/local_tee.hpp"
#include <memory>

namespace antiwasm {
std::unique_ptr<Instruction> parseInstruction(const uint8_t *instructionContent);
}
#endif // ANTIWASM_INSTRUCTION_PARSER_HPP
