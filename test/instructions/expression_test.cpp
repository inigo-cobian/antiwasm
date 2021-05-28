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
  Instruction instr{};

  expr.addInstruction(instr);

  BOOST_CHECK_EQUAL(false, expr.getInstructionVector().empty());
}

BOOST_AUTO_TEST_CASE(parseExpression_validCase) {
  auto * content = new uint8_t[3];
  content[0] = i32_const, content[1] = 0x05, content[2] = End;

  Expression expr = parseExpression(content);

  BOOST_CHECK_EQUAL(false, expr.hasError());
}

BOOST_AUTO_TEST_CASE(parseExpression_errorCase) {
  auto * content = new uint8_t[3];
  content[0] = error_instr, content[1] = 0x05, content[2] = End;

  Expression expr = parseExpression(content);

  BOOST_CHECK_EQUAL(true, expr.hasError());
}

BOOST_AUTO_TEST_SUITE_END() // expression_test
