#define BOOST_TEST_DYN_LINK

#include "const/f32_const.cpp"
#include "const/f64_const.cpp"
#include "const/i32_const.cpp"
#include "const/i64_const.cpp"
#include "instruction.cpp"
#include "instruction_parser.cpp"
#include "memory/load.cpp"
#include "memory/store.cpp"
#include "memory/memory_copy.cpp"
#include "memory/memory_fill.cpp"
#include "memory/memory_grow.cpp"
#include "memory/memory_size.cpp"
#include "memory/memory_init.cpp"
#include "memory/data_drop.cpp"
#include "nop.cpp"
#include "unreachable.cpp"
#include "variable/global_get.cpp"
#include "variable/global_set.cpp"
#include "variable/local_get.cpp"
#include "variable/local_set.cpp"
#include "variable/local_tee.cpp"
#include "comparison/i32_comparison.cpp"
#include <boost/test/unit_test.hpp>

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

BOOST_AUTO_TEST_CASE(parseI32Load_test) {
  uint8_t instrContent[] = {InstructionSet::i32_load, 0x0F, 0x0A};

  auto result = parseInstruction(instrContent);

  BOOST_CHECK_EQUAL(i32_load, result->getInstructionCode());
}

BOOST_AUTO_TEST_CASE(parseI64Load_test) {
  uint8_t instrContent[] = {InstructionSet::i64_load, 0x0F, 0x0A};

  auto result = parseInstruction(instrContent);

  BOOST_CHECK_EQUAL(i64_load, result->getInstructionCode());
}

BOOST_AUTO_TEST_CASE(parseF32Load_test) {
  uint8_t instrContent[] = {InstructionSet::f32_load, 0x0F, 0x0A};

  auto result = parseInstruction(instrContent);

  BOOST_CHECK_EQUAL(f32_load, result->getInstructionCode());
}

BOOST_AUTO_TEST_CASE(parseF64Load_test) {
  uint8_t instrContent[] = {InstructionSet::f64_load, 0x0F, 0x0A};

  auto result = parseInstruction(instrContent);

  BOOST_CHECK_EQUAL(f64_load, result->getInstructionCode());
}

BOOST_AUTO_TEST_CASE(parseI32Load8s_test) {
  uint8_t instrContent[] = {InstructionSet::i32_load8_s, 0x0F, 0x0A};

  auto result = parseInstruction(instrContent);

  BOOST_CHECK_EQUAL(i32_load8_s, result->getInstructionCode());
}

BOOST_AUTO_TEST_CASE(parseI32Load8u_test) {
  uint8_t instrContent[] = {InstructionSet::i32_load8_u, 0x0F, 0x0A};

  auto result = parseInstruction(instrContent);

  BOOST_CHECK_EQUAL(i32_load8_u, result->getInstructionCode());
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

BOOST_AUTO_TEST_SUITE_END() // instruction_parser_test
