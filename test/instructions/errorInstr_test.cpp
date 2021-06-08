#define BOOST_TEST_DYN_LINK

#include "errorInstr.hpp"
#include <boost/test/unit_test.hpp>

using namespace antiwasm;

BOOST_AUTO_TEST_SUITE(errorInstr_test)

BOOST_AUTO_TEST_CASE(constructor_caseUnrecognizedInstruction) {
  auto * content = new uint8_t{error_instr};

  ErrorInstr errorInstr(content);

  BOOST_CHECK_EQUAL(unrecognizedInstruction, errorInstr.getError()->errorType);
}

BOOST_AUTO_TEST_CASE(constructor_caseUnlinkedElseAtInstruction) {
  auto * content = new uint8_t{Else};

  ErrorInstr errorInstr(content);

  BOOST_CHECK_EQUAL(unlinkedElseAtInstruction, errorInstr.getError()->errorType);
}

BOOST_AUTO_TEST_CASE(constructor_caseUnrecognizedDoubleByteInstruction) {
  auto * content = new uint8_t[2];
  content[0] = double_byte_instr, content[1] = error_instr;

  ErrorInstr errorInstr(content);

  BOOST_CHECK_EQUAL(unrecognizedDoubleByteInstruction, errorInstr.getError()->errorType);
}

BOOST_AUTO_TEST_CASE(getInvalidInstrByte_caseUnrecognizedInstruction) {
  auto * content = new uint8_t{error_instr};

  ErrorInstr errorInstr(content);

  BOOST_CHECK_EQUAL(error_instr, errorInstr.getInvalidInstrByte());
}

BOOST_AUTO_TEST_CASE(getInvalidInstrByte_caseUnrecognizedDoubleByteInstruction) {
  auto * content = new uint8_t[2];
  content[0] = double_byte_instr, content[1] = error_instr;

  ErrorInstr errorInstr(content);

  BOOST_CHECK_EQUAL(error_instr, errorInstr.getInvalidInstrByte());
}

BOOST_AUTO_TEST_SUITE_END() // errorInstr_test
