#include "instruction_parser.hpp"

namespace antiwasm {
std::unique_ptr<Instruction> parseInstruction(const uint8_t *instructionContent) {
  switch (instructionContent[0]) {
  case Unreachable:
    return std::make_unique<Instruction>(UnreachableInstr{});
  case Nop:
    return std::make_unique<Instruction>(NopInstr{});
  case Block:
    return std::make_unique<Instruction>(BlockInstr{instructionContent});
  case Loop:
    return std::make_unique<Instruction>(LoopInstr{instructionContent});
  case If:
    return std::make_unique<Instruction>(IfInstr{instructionContent});
  case Br:
    return std::make_unique<Instruction>(BrInstr{instructionContent});
  case Br_if:
    return std::make_unique<Instruction>(BrIfInstr{instructionContent});
  case Br_table:
    return std::make_unique<Instruction>(BrTableInstr{instructionContent});
  case Return:
    return std::make_unique<Instruction>(ReturnInstr{});
  case Call:
    return std::make_unique<Instruction>(CallInstr{instructionContent});
  case Call_indirect:
    return std::make_unique<Instruction>(CallIndirectInstr{instructionContent});
  case Drop:
    // return std::make_unique<Instruction>(DropInstr{instructionContent});
  case Select:
    // return std::make_unique<Instruction>(SelectInstr{instructionContent});

  case Local_get:
    return std::make_unique<Instruction>(LocalGet{instructionContent});
  case Local_set:
    return std::make_unique<Instruction>(LocalSet{instructionContent});
  case Local_tee:
    return std::make_unique<Instruction>(LocalTee{instructionContent});
  case Global_get:
    return std::make_unique<Instruction>(GlobalGet{instructionContent});
  case Global_set:
    return std::make_unique<Instruction>(GlobalSet{instructionContent});

  case Table_get:
    return std::make_unique<Instruction>(TableGet{instructionContent});
  case Table_set:
    return std::make_unique<Instruction>(TableSet{instructionContent});

  case i32_load:
  case i64_load:
  case f32_load:
  case f64_load:
  case i32_load8_s:
  case i32_load8_u:
  case i32_load16_s:
  case i32_load16_u:
  case i64_load8_s:
  case i64_load8_u:
  case i64_load16_s:
  case i64_load16_u:
  case i64_load32_s:
  case i64_load32_u:
    return std::make_unique<Instruction>(LoadInstr{instructionContent});

  case i32_store:
  case i64_store:
  case f32_store:
  case f64_store:
  case i32_store8:
  case i32_store16:
  case i64_store8:
  case i64_store16:
  case i64_store32:
    return std::make_unique<Instruction>(StoreInstr{instructionContent});

  case Memory_size:
    return std::make_unique<Instruction>(MemorySize{});
  case Memory_grow:
    return std::make_unique<Instruction>(MemoryGrow{});

  case i32_const:
    return std::make_unique<Instruction>(I32Const{instructionContent});
  case i64_const:
    return std::make_unique<Instruction>(I64Const{instructionContent});
  case f32_const:
    return std::make_unique<Instruction>(F32Const{instructionContent});
  case f64_const:
    return std::make_unique<Instruction>(F64Const{instructionContent});

  case i32_eqz:
  case i32_eq:
  case i32_ne:
  case i32_lt_s:
  case i32_lt_u:
  case i32_gt_s:
  case i32_gt_u:
  case i32_le_s:
  case i32_le_u:
  case i32_ge_s:
  case i32_ge_u:

  case i64_eqz:
  case i64_eq:
  case i64_ne:
  case i64_lt_s:
  case i64_lt_u:
  case i64_gt_s:
  case i64_gt_u:
  case i64_le_s:
  case i64_le_u:
  case i64_ge_s:
  case i64_ge_u:

  case f32_eq:
  case f32_ne:
  case f32_lt:
  case f32_gt:
  case f32_le:
  case f32_ge:

  case f64_eq:
  case f64_ne:
  case f64_lt:
  case f64_gt:
  case f64_le:
  case f64_ge:

  case i32_clz:
  case i32_ctz:
  case i32_popcnt:

  case i32_add:
  case i32_sub:
  case i32_mul:
  case i32_div_s:
  case i32_div_u:
  case i32_rem_s:
  case i32_rem_u:

  case i32_and:
  case i32_or:
  case i32_xor:

  case i32_shl:
  case i32_shr_s:
  case i32_shr_u:
  case i32_rotl:
  case i32_rotr:

  case i64_clz:
  case i64_ctz:
  case i64_popcnt:

  case i64_add:
  case i64_sub:
  case i64_mul:
  case i64_div_s:
  case i64_div_u:
  case i64_rem_s:
  case i64_rem_u:

  case i64_and:
  case i64_or:
  case i64_xor:

  case i64_shl:
  case i64_shr_s:
  case i64_shr_u:
  case i64_rotl:
  case i64_rotr:

  case f32_abs:
  case f32_neg:
  case f32_ceil:
  case f32_floor:
  case f32_trunc:
  case f32_nearest:

  case f32_sqrt:
  case f32_add:
  case f32_sub:
  case f32_mul:
  case f32_div:

  case f32_min:
  case f32_max:
  case f32_copysign:

  case f64_abs:
  case f64_neg:
  case f64_ceil:
  case f64_floor:
  case f64_trunc:
  case f64_nearest:

  case f64_sqrt:
  case f64_add:
  case f64_sub:
  case f64_mul:
  case f64_div:

  case f64_min:
  case f64_max:
  case f64_copysign:
    return std::make_unique<Instruction>(NumericInstr{instructionContent});

  case i32_wrap_i64:
  case i32_trunc_f32_s:
  case i32_trunc_f32_u:
  case i32_trunc_f64_s:
  case i32_trunc_f64_u:
  case i64_extend_i32_s:
  case i64_extend_i32_u:
  case i64_trunc_f32_s:
  case i64_trunc_f32_u:
  case i64_trunc_f64_s:
  case i64_trunc_f64_u:
  case f32_convert_i32_s:
  case f32_convert_i32_u:
  case f32_convert_i64_s:
  case f32_convert_i64_u:
  case f32_demote_f64:
  case f64_convert_i32_s:
  case f64_convert_i32_u:
  case f64_convert_i64_s:
  case f64_convert_i64_u:
  case f64_promote_f32:
  case i32_reinterpret_f32:
  case i64_reinterpret_f64:
  case f32_reinterpret_i32:
  case f64_reinterpret_i64:
    return std::make_unique<Instruction>(TypeConversion{instructionContent});

  case i32_extend8_s:
  case i32_extend16_s:
  case i64_extend8_s:
  case i64_extend16_s:
  case i64_extend32_s:
    return std::make_unique<Instruction>(ExtensionInstr{instructionContent});

  case Ref_null:
    return std::make_unique<Instruction>(RefNull{instructionContent});
  case Ref_is_null:
    return std::make_unique<Instruction>(RefIsNull{instructionContent});
  case Ref_func:
    return std::make_unique<Instruction>(RefFunc{instructionContent});

  case double_byte_instr:
    switch (instructionContent[1]) {
    case i32_trunc_sat_f32_s:
    case i32_trunc_sat_f32_u:
    case i32_trunc_sat_f64_s:
    case i32_trunc_sat_f64_u:
    case i64_trunc_sat_f32_s:
    case i64_trunc_sat_f32_u:
    case i64_trunc_sat_f64_s:
    case i64_trunc_sat_f64_u:
      return std::make_unique<Instruction>(SaturatingTrunc{instructionContent});

    case Memory_init:
      return std::make_unique<Instruction>(MemoryInit{instructionContent});
    case Data_drop:
      return std::make_unique<Instruction>(DataDrop{instructionContent});
    case Memory_copy:
      return std::make_unique<Instruction>(MemoryCopy{});
    case Memory_fill:
      return std::make_unique<Instruction>(MemoryFill{});
    case Table_init:
      return std::make_unique<Instruction>(TableInit{instructionContent});
    case Elem_drop:
      return std::make_unique<Instruction>(ElemDrop{instructionContent});
    case Table_copy:
      return std::make_unique<Instruction>(TableCopy{instructionContent});
    case Table_grow:
      return std::make_unique<Instruction>(TableGrow{instructionContent});
    case Table_size:
      return std::make_unique<Instruction>(TableSize{instructionContent});
    case Table_fill:
      return std::make_unique<Instruction>(TableFill{instructionContent});

    default:
        // TODO unknown or invalid value
        ;
    }

  case Else:
    // TODO unlinked else
  default:
      // TODO unknown or invalid value
      ;
  }
  return std::make_unique<Instruction>(Instruction{});
}

std::vector<std::unique_ptr<Instruction>> parseInstructionSet(const uint8_t *instructionsContent, uint32_t &nBytes) {
  std::vector<std::unique_ptr<Instruction>> instrVec;

  uint32_t pos = 0;
  while (instructionsContent[pos] != InstructionSet::End) {
    std::unique_ptr<Instruction> instr = parseInstruction(instructionsContent + pos);

    if (instr->hasError()) {
      auto error = generateError(fatal, unrecognizedInstructionAtBlock, instrVec.size());
      instrVec.push_back(std::move(instr));
      break;
    }

    pos += instr->getNBytes();
    instrVec.push_back(std::move(instr));
  }
  // TODO add EndInstr ?
  nBytes = pos + 2; // 0x0B byte and correction pos to size
  return instrVec;
}

std::vector<std::unique_ptr<Instruction>> parseIfInstructionSet(const uint8_t *instructionsContent, uint32_t &nBytes) {
  BOOST_LOG_TRIVIAL(debug) << "[instruction_parser] Parsing if instruction set";
  std::vector<std::unique_ptr<Instruction>> instrVec;

  uint32_t pos = 0;
  while (instructionsContent[pos] != InstructionSet::End && instructionsContent[pos] != InstructionSet::Else) {
    std::unique_ptr<Instruction> instr = parseInstruction(instructionsContent + pos);
    BOOST_LOG_TRIVIAL(debug) << "[instruction_parser] Parsing instr set at pos [" << (int)pos << "]";

    if (instr->hasError()) {
      BOOST_LOG_TRIVIAL(debug) << "[instruction_parser] Unrecognized instruction";
      auto error = generateError(fatal, unrecognizedInstructionAtBlock, instrVec.size());
      instrVec.push_back(std::move(instr));
      break;
    }

    pos += instr->getNBytes();
    instrVec.push_back(std::move(instr));
  }
  if (instructionsContent[pos] == InstructionSet::Else) {
    BOOST_LOG_TRIVIAL(debug) << "[instruction_parser] Else instr at pos [" << (int)pos << "]";

    std::unique_ptr<Instruction> instr = std::make_unique<Instruction>(ElseInstr{instructionsContent + pos});
    pos += instr->getNBytes();
    instrVec.push_back(std::move(instr));
  }
  // TODO add EndInstr ?
  nBytes = pos + 1; // 0x0B end byte

  BOOST_LOG_TRIVIAL(debug) << "[instruction_parser] Final pos while parsing if at [" << (int)pos << "]";
  return instrVec;
}
} // namespace antiwasm