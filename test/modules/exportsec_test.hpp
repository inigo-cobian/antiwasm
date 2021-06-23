#ifndef ANTIWASM_EXPORTSEC_TEST_HPP
#define ANTIWASM_EXPORTSEC_TEST_HPP

#include "exportsec.hpp"
#include <boost/test/unit_test.hpp>

antiwasm::Export generateExport() {
  auto *exportContent = new uint8_t[8];
  exportContent[0] = 4; // size of Name
  exportContent[1] = 't', exportContent[2] = 'e', exportContent[3] = 's', exportContent[4] = 't';
  exportContent[5] = antiwasm::ExportDesc::funcidxExport;
  exportContent[6] = 0x00;

  auto export_ = antiwasm::parseExport(exportContent);
  return export_;
}

#endif // ANTIWASM_EXPORTSEC_TEST_HPP
