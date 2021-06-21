#ifndef ANTIWASM_EXPORT_HPP
#define ANTIWASM_EXPORT_HPP

#include "nameParser.hpp"
#include "leb128.hpp"
#include <cstdint>
#include <sstream>
#include <string>
#include <utility>

namespace antiwasm {
enum ExportDesc : uint8_t {
  funcidxExport = 0x00,
  tableidxExport = 0x01,
  memidxExport = 0x02,
  globalidxExport = 0x03,
  invalid_exportDesc = 0xAA
};

struct Export : public ContentBlock {
  UTF8Name name;
  ExportDesc exportDesc;
  uint32_t index;

  Export(UTF8Name  name_, ExportDesc exportDesc_, uint32_t index_);
  [[nodiscard]] std::string getAsText() const;
};

/**
 * Parses and returns the valid ExportDesc.
 * Returns invalid_exportDesc if invalid value.
 * @param exportDescContent
 * @return
 */
ExportDesc parseExportDesc(uint8_t exportDescContent);

/**
 * Parses and generates the parsed Export.
 * Adds error if cannot complete the parsing.
 * @param exportContent
 * @return
 */
Export parseExport(const uint8_t *exportContent);

} // namespace antiwasm

#endif // ANTIWASM_EXPORT_HPP
