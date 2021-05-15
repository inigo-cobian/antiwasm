#define BOOST_TEST_DYN_LINK

#include "f32_const.cpp"
#include "f64_const.cpp"
#include "i32_const.cpp"
#include "i64_const.cpp"
#include "instruction.cpp"
#include "instruction_parser.cpp"
#include "nop.cpp"
#include "unreachable.cpp"
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

BOOST_AUTO_TEST_SUITE_END() // limits_test
