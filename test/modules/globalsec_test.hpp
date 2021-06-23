#ifndef ANTIWASM_GLOBALSEC_TEST_HPP
#define ANTIWASM_GLOBALSEC_TEST_HPP

#include "globalsec.hpp"
#include <boost/test/unit_test.hpp>

antiwasm::Global generateGlobal() {
  auto *globalContent = new uint8_t[6];
  globalContent[0] = Mut::var_;
  globalContent[1] = antiwasm::Numtype::i32;
  globalContent[2] = InstructionSet::Nop, globalContent[3] = InstructionSet::End;

  auto global = antiwasm::parseGlobal(globalContent);
  return global;
}


#endif // ANTIWASM_GLOBALSEC_TEST_HPP
