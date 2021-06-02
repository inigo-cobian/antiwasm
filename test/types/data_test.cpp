#define BOOST_TEST_DYN_LINK

#include "data_test.hpp"

using namespace antiwasm;

BOOST_AUTO_TEST_SUITE(data_test)
BOOST_AUTO_TEST_CASE(parseData_caseModeActive_mem0_correct) {
  auto *dataContent = new uint8_t[6];
  dataContent[0] = 0x00; // caseModeActive_mem0
  dataContent[1] = InstructionSet::Nop, dataContent[2] = InstructionSet::End;
  dataContent[3] = 0x02; // The other two bytes are not relevant

  auto data = parseData(dataContent);

  BOOST_CHECK_EQUAL(modeActive_mem0, data.dataType);
}

BOOST_AUTO_TEST_CASE(parseData_caseModeActive_mem0_incorrect) {
  auto *dataContent = new uint8_t[6];
  dataContent[0] = 0x00; // caseModeActive_mem0
  dataContent[1] = InstructionSet::Else, dataContent[2] = InstructionSet::End; // Invalid expr
  dataContent[3] = 0x02; // The other two bytes are not relevant

  auto data = parseData(dataContent);

  BOOST_CHECK_EQUAL(modeActive_mem0, data.dataType);
  BOOST_CHECK_EQUAL(true, data.hasError());
}

BOOST_AUTO_TEST_CASE(parseData_caseModePassive) {
  auto *dataContent = new uint8_t[4];
  dataContent[0] = 0x01; // modePassive
  dataContent[1] = 0x02; // The other two bytes are not relevant

  auto data = parseData(dataContent);

  BOOST_CHECK_EQUAL(modePassive, data.dataType);
}

BOOST_AUTO_TEST_CASE(parseData_caseModeActive_memX_correct) {
  auto *dataContent = new uint8_t[6];
  dataContent[0] = 0x02; // caseModeActive_memX
  dataContent[1] = 0x00; // memidx
  dataContent[2] = InstructionSet::Nop, dataContent[3] = InstructionSet::End;
  dataContent[4] = 0x02; // The other two bytes are not relevant

  auto data = parseData(dataContent);

  BOOST_CHECK_EQUAL(modeActive_memX, data.dataType);
}

BOOST_AUTO_TEST_CASE(parseData_caseModeActive_memX_incorrect) {
  auto *dataContent = new uint8_t[6];
  dataContent[0] = 0x02; // caseModeActive_memX
  dataContent[1] = 0x00; // memidx
  dataContent[2] = InstructionSet::Else, dataContent[3] = InstructionSet::End; // Invalid expr
  dataContent[4] = 0x02; // The other two bytes are not relevant

  auto data = parseData(dataContent);

  BOOST_CHECK_EQUAL(modeActive_memX, data.dataType);
  BOOST_CHECK_EQUAL(true, data.hasError());
}

BOOST_AUTO_TEST_CASE(parseData_caseUnknownHeader) {
  auto *dataContent = new uint8_t[6];
  dataContent[0] = 0x09; // unknown byte
  // Other bytes should not be taken into account

  auto data = parseData(dataContent);

  BOOST_CHECK_EQUAL(error_data_type, data.dataType);
  BOOST_CHECK_EQUAL(unrecognizedDataHeader, data.getError()->errorType);
}

BOOST_AUTO_TEST_SUITE_END() // data_test
