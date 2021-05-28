#define BOOST_TEST_DYN_LINK

#include "expression.hpp"
#include <boost/test/unit_test.hpp>

using namespace antiwasm;

BOOST_AUTO_TEST_SUITE(expression_test)

BOOST_AUTO_TEST_CASE(constructor_expressionTest) {

  Expression expr{};

  BOOST_CHECK_EQUAL(0, expr.getNBytes());
}

BOOST_AUTO_TEST_CASE(getInstructionVector_empty) {
  Expression expr{};

  auto instrVec = expr.getInstructionVector();

  BOOST_CHECK_EQUAL(true, instrVec.empty());
}

BOOST_AUTO_TEST_CASE(addInstruction_consti32Case) {
  Expression expr{};
  uint8_t instrContent[] = {i32_const, 0x05};
  I32Const instr{instrContent};

  expr.addInstruction(instr);

  BOOST_CHECK_EQUAL(false, expr.getInstructionVector().empty());
  BOOST_CHECK_EQUAL(2, expr.getNBytes());
}

BOOST_AUTO_TEST_CASE(addInstruction_instrHasErrorCase) {
  Expression expr{};
  Instruction instr{};
  // TODO

  expr.addInstruction(instr);

  // BOOST_CHECK_EQUAL(true, expr.hasError()); FIXME
}

BOOST_AUTO_TEST_SUITE_END() // expression_test
