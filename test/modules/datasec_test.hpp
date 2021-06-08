#ifndef ANTIWASM_DATASEC_TEST_HPP
#define ANTIWASM_DATASEC_TEST_HPP

#include "datasec.cpp"
#include <boost/test/unit_test.hpp>

antiwasm::Data generateData() {
  auto *dataContent = new uint8_t[6];
  dataContent[0] = 0x00; // caseModeActive_mem0
  dataContent[1] = InstructionSet::Nop, dataContent[2] = InstructionSet::End;
  dataContent[3] = 0x02; // The other two bytes are not relevant

  auto data = antiwasm::parseData(dataContent);
  return data;
}

#endif // ANTIWASM_DATASEC_TEST_HPP
