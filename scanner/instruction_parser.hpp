#ifndef ANTIWASM_INSTRUCTION_PARSER_HPP
#define ANTIWASM_INSTRUCTION_PARSER_HPP

#include "control/block.hpp"
#include "control/br.hpp"
#include "control/br_if.hpp"
#include "control/br_table.hpp"
#include "control/call.hpp"
#include "control/call_indirect.hpp"
#include "control/else.hpp"
#include "control/if.hpp"
#include "control/loop.hpp"
#include "control/nop.hpp"
#include "control/return.hpp"
#include "control/unreachable.hpp"
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
#include "numeric/extension.hpp"
#include "numeric/f32_const.hpp"
#include "numeric/f64_const.hpp"
#include "numeric/i32_const.hpp"
#include "numeric/i64_const.hpp"
#include "numeric/numericInstr.hpp"
#include "numeric/saturating_truc.hpp"
#include "numeric/type_conversion.hpp"
#include "table/elem_drop.hpp"
#include "table/table_copy.hpp"
#include "table/table_fill.hpp"
#include "table/table_get.hpp"
#include "table/table_grow.hpp"
#include "table/table_init.hpp"
#include "table/table_set.hpp"
#include "table/table_size.hpp"
#include "variable/global_get.hpp"
#include "variable/global_set.hpp"
#include "variable/local_get.hpp"
#include "variable/local_set.hpp"
#include "variable/local_tee.hpp"
#include <memory>
#include <reference/ref_func.hpp>
#include <reference/ref_is_null.hpp>
#include <reference/ref_null.hpp>

namespace antiwasm {
std::unique_ptr<Instruction> parseInstruction(const uint8_t *instructionContent);
std::vector<std::unique_ptr<Instruction>> parseInstructionSet(const uint8_t *instructionsContent, uint32_t &nBytes);
std::vector<std::unique_ptr<Instruction>> parseIfInstructionSet(const uint8_t *instructionsContent, uint32_t &nBytes);
} // namespace antiwasm
#endif // ANTIWASM_INSTRUCTION_PARSER_HPP
