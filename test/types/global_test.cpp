#define BOOST_TEST_DYN_LINK

#include "global_test.hpp"

using namespace antiwasm;

BOOST_AUTO_TEST_SUITE(global_test)

BOOST_AUTO_TEST_CASE(parseGlobal_correctlyFormatted) {
  auto *globalContent = new uint8_t[6];
  globalContent[0] = Mut::var_;
  globalContent[1] = Numtype::i32;
  globalContent[2] = InstructionSet::Nop, globalContent[3] = InstructionSet::End;

  auto global = parseGlobal(globalContent);

  BOOST_CHECK_EQUAL(false, global.hasError());
}

BOOST_AUTO_TEST_SUITE_END() // global_test
