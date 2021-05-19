#define BOOST_TEST_DYN_LINK

#include "control/br.cpp"
#include "control/br_if.cpp"
#include "control/br_table.cpp"
#include "control/call.cpp"
#include "control/call_indirect.cpp"
#include "control/return.cpp"
#include "instruction.cpp"
#include "instruction_parser.cpp"
#include "memory/data_drop.cpp"
#include "memory/load.cpp"
#include "memory/memory_copy.cpp"
#include "memory/memory_fill.cpp"
#include "memory/memory_grow.cpp"
#include "memory/memory_init.cpp"
#include "memory/memory_size.cpp"
#include "memory/store.cpp"
#include "nop.cpp"
#include "numeric/extension.cpp"
#include "numeric/f32_const.cpp"
#include "numeric/f64_const.cpp"
#include "numeric/i32_const.cpp"
#include "numeric/i64_const.cpp"
#include "numeric/numericInstr.cpp"
#include "numeric/saturating_truc.cpp"
#include "numeric/type_conversion.cpp"
#include "table/elem_drop.cpp"
#include "table/table_copy.cpp"
#include "table/table_fill.cpp"
#include "table/table_get.cpp"
#include "table/table_grow.cpp"
#include "table/table_init.cpp"
#include "table/table_set.cpp"
#include "table/table_size.cpp"
#include "unreachable.cpp"
#include "variable/global_get.cpp"
#include "variable/global_set.cpp"
#include "variable/local_get.cpp"
#include "variable/local_set.cpp"
#include "variable/local_tee.cpp"
#include <boost/test/unit_test.hpp>
#include <reference/ref_func.cpp>
#include <reference/ref_is_null.cpp>
#include <reference/ref_null.cpp>

using namespace antiwasm;

BOOST_AUTO_TEST_SUITE(instruction_parser_test)

BOOST_AUTO_TEST_CASE(parseUnreachable_test) {
  uint8_t instrContent[] = {InstructionSet::Unreachable};

  auto result = parseInstruction(instrContent);

  BOOST_CHECK_EQUAL(Unreachable, result->getInstructionCode());
}

BOOST_AUTO_TEST_CASE(parseNop_test) {
  uint8_t instrContent[] = {InstructionSet::Nop};

  auto result = parseInstruction(instrContent);

  BOOST_CHECK_EQUAL(Nop, result->getInstructionCode());
}

BOOST_AUTO_TEST_CASE(parsei32const_test) {
  uint8_t instrContent[] = {InstructionSet::i32_const, 0x0F};

  auto result = parseInstruction(instrContent);

  BOOST_CHECK_EQUAL(i32_const, result->getInstructionCode());
}

BOOST_AUTO_TEST_CASE(parsei64const_test) {
  uint8_t instrContent[] = {InstructionSet::i64_const, 0x0F};

  auto result = parseInstruction(instrContent);

  BOOST_CHECK_EQUAL(i64_const, result->getInstructionCode());
}

BOOST_AUTO_TEST_CASE(parsef32const_test) {
  auto *instrContent = new uint8_t[5];
  instrContent[0] = InstructionSet::f32_const;
  instrContent[1] = 0x3f, instrContent[2] = 0x9d, instrContent[3] = 0xf3, instrContent[4] = 0xb6;

  auto result = parseInstruction(instrContent);

  BOOST_CHECK_EQUAL(f32_const, result->getInstructionCode());
}

BOOST_AUTO_TEST_CASE(parsef64const_test) {
  auto *instrContent = new uint8_t[9];
  instrContent[0] = InstructionSet::f64_const;
  instrContent[1] = 0x40, instrContent[2] = 0x50, instrContent[3] = 0x5b, instrContent[4] = 0x85;
  instrContent[5] = 0x1e, instrContent[6] = 0xb8, instrContent[7] = 0x51, instrContent[8] = 0xec;

  auto result = parseInstruction(instrContent);

  BOOST_CHECK_EQUAL(f64_const, result->getInstructionCode());
}

BOOST_AUTO_TEST_CASE(parseLocalGet_test) {
  uint8_t instrContent[] = {InstructionSet::Local_get, 0x0F};

  auto result = parseInstruction(instrContent);

  BOOST_CHECK_EQUAL(Local_get, result->getInstructionCode());
}

BOOST_AUTO_TEST_CASE(parseLocalSet_test) {
  uint8_t instrContent[] = {InstructionSet::Local_set, 0x0F};

  auto result = parseInstruction(instrContent);

  BOOST_CHECK_EQUAL(Local_set, result->getInstructionCode());
}

BOOST_AUTO_TEST_CASE(parseLocalTee_test) {
  uint8_t instrContent[] = {InstructionSet::Local_tee, 0x0F};

  auto result = parseInstruction(instrContent);

  BOOST_CHECK_EQUAL(Local_tee, result->getInstructionCode());
}

BOOST_AUTO_TEST_CASE(parseGlobalGet_test) {
  uint8_t instrContent[] = {InstructionSet::Global_get, 0x0F};

  auto result = parseInstruction(instrContent);

  BOOST_CHECK_EQUAL(Global_get, result->getInstructionCode());
}

BOOST_AUTO_TEST_CASE(parseGlobalSet_test) {
  uint8_t instrContent[] = {InstructionSet::Global_set, 0x0F};

  auto result = parseInstruction(instrContent);

  BOOST_CHECK_EQUAL(Global_set, result->getInstructionCode());
}

BOOST_AUTO_TEST_CASE(parseI32Load8s_test) {
  uint8_t instrContent[] = {InstructionSet::i32_load8_s, 0x0F, 0x0A};

  auto result = parseInstruction(instrContent);

  BOOST_CHECK_EQUAL(i32_load8_s, result->getInstructionCode());
}

BOOST_AUTO_TEST_CASE(parseStore_test) {
  uint8_t instrContent[] = {InstructionSet::i64_store32, 0x0F, 0x0A};

  auto result = parseInstruction(instrContent);

  BOOST_CHECK_EQUAL(i64_store32, result->getInstructionCode());
}

BOOST_AUTO_TEST_CASE(parseDoubleByteInstr_test) {
  uint8_t instrContent[] = {InstructionSet::double_byte_instr, SecondByteSet::Memory_copy};

  auto result = parseInstruction(instrContent);

  BOOST_CHECK_EQUAL(double_byte_instr, result->getInstructionCode());
}

BOOST_AUTO_TEST_CASE(parseMemoryCopy_test) {
  uint8_t instrContent[] = {InstructionSet::double_byte_instr, SecondByteSet::Memory_copy};

  auto result = parseInstruction(instrContent);

  BOOST_CHECK_EQUAL(Memory_copy, result->getSecondByte());
}

BOOST_AUTO_TEST_CASE(parseMemoryFill_test) {
  uint8_t instrContent[] = {InstructionSet::double_byte_instr, SecondByteSet::Memory_fill};

  auto result = parseInstruction(instrContent);

  BOOST_CHECK_EQUAL(Memory_fill, result->getSecondByte());
}

BOOST_AUTO_TEST_CASE(parseMemoryGrow_test) {
  uint8_t instrContent[] = {InstructionSet::Memory_grow};

  auto result = parseInstruction(instrContent);

  BOOST_CHECK_EQUAL(Memory_grow, result->getInstructionCode());
}

BOOST_AUTO_TEST_CASE(parseMemorySize_test) {
  uint8_t instrContent[] = {InstructionSet::Memory_size};

  auto result = parseInstruction(instrContent);

  BOOST_CHECK_EQUAL(Memory_size, result->getInstructionCode());
}

BOOST_AUTO_TEST_CASE(parseMemoryInit_test) {
  uint8_t instrContent[] = {InstructionSet::double_byte_instr, SecondByteSet::Memory_init, 0x0A};

  auto result = parseInstruction(instrContent);

  BOOST_CHECK_EQUAL(Memory_init, result->getSecondByte());
}

BOOST_AUTO_TEST_CASE(parseDataDrop_test) {
  uint8_t instrContent[] = {InstructionSet::double_byte_instr, SecondByteSet::Data_drop, 0x0A};

  auto result = parseInstruction(instrContent);

  BOOST_CHECK_EQUAL(Data_drop, result->getSecondByte());
}

BOOST_AUTO_TEST_CASE(parseNumericInstr_test) {
  uint8_t instrContent[] = {InstructionSet::i32_and};

  auto result = parseInstruction(instrContent);

  BOOST_CHECK_EQUAL(i32_and, result->getInstructionCode());
}

BOOST_AUTO_TEST_CASE(parseSaturatingTrunc_test) {
  uint8_t instrContent[] = {InstructionSet::double_byte_instr, SecondByteSet::i64_trunc_sat_f64_u};

  auto result = parseInstruction(instrContent);

  BOOST_CHECK_EQUAL(i64_trunc_sat_f64_u, result->getSecondByte());
}

BOOST_AUTO_TEST_CASE(parseTableGet_test) {
  uint8_t instrContent[] = {InstructionSet::Table_get, 0x04};

  auto result = parseInstruction(instrContent);

  BOOST_CHECK_EQUAL(Table_get, result->getInstructionCode());
}

BOOST_AUTO_TEST_CASE(parseTableSet_test) {
  uint8_t instrContent[] = {InstructionSet::Table_set, 0x04};

  auto result = parseInstruction(instrContent);

  BOOST_CHECK_EQUAL(Table_set, result->getInstructionCode());
}

BOOST_AUTO_TEST_CASE(parseTableInit_test) {
  uint8_t instrContent[] = {InstructionSet::double_byte_instr, SecondByteSet::Table_init, 0x04, 0x10};

  auto result = parseInstruction(instrContent);

  BOOST_CHECK_EQUAL(Table_init, result->getSecondByte());
}

BOOST_AUTO_TEST_CASE(parseElemDrop_test) {
  uint8_t instrContent[] = {InstructionSet::double_byte_instr, SecondByteSet::Elem_drop, 0x04};

  auto result = parseInstruction(instrContent);

  BOOST_CHECK_EQUAL(Elem_drop, result->getSecondByte());
}

BOOST_AUTO_TEST_CASE(parseTableCopy_test) {
  uint8_t instrContent[] = {InstructionSet::double_byte_instr, SecondByteSet::Table_copy, 0x04, 0x10};

  auto result = parseInstruction(instrContent);

  BOOST_CHECK_EQUAL(Table_copy, result->getSecondByte());
}

BOOST_AUTO_TEST_CASE(parseTableGrow_test) {
  uint8_t instrContent[] = {InstructionSet::double_byte_instr, SecondByteSet::Table_grow, 0x04};

  auto result = parseInstruction(instrContent);

  BOOST_CHECK_EQUAL(Table_grow, result->getSecondByte());
}

BOOST_AUTO_TEST_CASE(parseTableSize_test) {
  uint8_t instrContent[] = {InstructionSet::double_byte_instr, SecondByteSet::Table_size, 0x04};

  auto result = parseInstruction(instrContent);

  BOOST_CHECK_EQUAL(Table_size, result->getSecondByte());
}

BOOST_AUTO_TEST_CASE(parseTableFill_test) {
  uint8_t instrContent[] = {InstructionSet::double_byte_instr, SecondByteSet::Table_fill, 0x04};

  auto result = parseInstruction(instrContent);

  BOOST_CHECK_EQUAL(Table_fill, result->getSecondByte());
}

BOOST_AUTO_TEST_CASE(parseTypeConversion_test) {
  uint8_t instrContent[] = {InstructionSet::f64_convert_i32_s};

  auto result = parseInstruction(instrContent);

  BOOST_CHECK_EQUAL(f64_convert_i32_s, result->getInstructionCode());
}

BOOST_AUTO_TEST_CASE(parseExtension_test) {
  uint8_t instrContent[] = {InstructionSet::i64_extend16_s};

  auto result = parseInstruction(instrContent);

  BOOST_CHECK_EQUAL(i64_extend16_s, result->getInstructionCode());
}

BOOST_AUTO_TEST_CASE(parseRefNull_test) {
  uint8_t instrContent[] = {InstructionSet::Ref_null};

  auto result = parseInstruction(instrContent);

  BOOST_CHECK_EQUAL(Ref_null, result->getInstructionCode());
}

BOOST_AUTO_TEST_CASE(parseRefIsNull_test) {
  uint8_t instrContent[] = {InstructionSet::Ref_is_null};

  auto result = parseInstruction(instrContent);

  BOOST_CHECK_EQUAL(Ref_is_null, result->getInstructionCode());
}

BOOST_AUTO_TEST_CASE(parseRefFunc_test) {
  uint8_t instrContent[] = {InstructionSet::Ref_func};

  auto result = parseInstruction(instrContent);

  BOOST_CHECK_EQUAL(Ref_func, result->getInstructionCode());
}

BOOST_AUTO_TEST_CASE(parseBrInstr_test) {
  uint8_t instrContent[] = {InstructionSet::Br};

  auto result = parseInstruction(instrContent);

  BOOST_CHECK_EQUAL(Br, result->getInstructionCode());
}

BOOST_AUTO_TEST_CASE(parseBrIfInstr_test) {
  uint8_t instrContent[] = {InstructionSet::Br_if};

  auto result = parseInstruction(instrContent);

  BOOST_CHECK_EQUAL(Br_if, result->getInstructionCode());
}

BOOST_AUTO_TEST_CASE(parseBrTableInstr_test) {
  uint8_t instrContent[] = {InstructionSet::Br_table};

  auto result = parseInstruction(instrContent);

  BOOST_CHECK_EQUAL(Br_table, result->getInstructionCode());
}

BOOST_AUTO_TEST_CASE(parseReturnInstr_test) {
  uint8_t instrContent[] = {InstructionSet::Return};

  auto result = parseInstruction(instrContent);

  BOOST_CHECK_EQUAL(Return, result->getInstructionCode());
}

BOOST_AUTO_TEST_CASE(parseCallInstr_test) {
  uint8_t instrContent[] = {InstructionSet::Call};

  auto result = parseInstruction(instrContent);

  BOOST_CHECK_EQUAL(Call, result->getInstructionCode());
}

BOOST_AUTO_TEST_CASE(parseCallIndirectInstr_test) {
  uint8_t instrContent[] = {InstructionSet::Call_indirect};

  auto result = parseInstruction(instrContent);

  BOOST_CHECK_EQUAL(Call_indirect, result->getInstructionCode());
}

BOOST_AUTO_TEST_SUITE_END() // instruction_parser_test
