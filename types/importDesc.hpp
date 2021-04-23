#ifndef ANTIWASM_IMPORTDESC_HPP
#define ANTIWASM_IMPORTDESC_HPP

#include "contentBlock.hpp"
#include "globaltype.hpp"
#include "memtype.hpp"
#include "tabletype.hpp"
#include <cstdint>

namespace antiwasm {

enum ImportDescType : uint8_t { ImportFunc = 0x00, ImportTable = 0x01, ImportMemtype = 0x02, ImportGlobaltype = 0x03 };

union ImportDescContent {
  uint32_t typeIdx;
  Tabletype tabletype;
  Memtype memtype;
  Globaltype globaltype;
};

// TODO importDesc is not as grammar-like as the others. Explain why.
struct ImportDesc : public ContentBlock {
  ImportDescType type_;
  ImportDescContent content_;
};

/**
 * Parses and generates the parsed Importdesc.
 * Adds error if cannot complete the parsing.
 * @param ImportDescContent
 * @return
 */
ImportDesc parseImportDesc(const uint8_t *importDescContent);
} // namespace antiwasm
#endif // ANTIWASM_IMPORTDESC_HPP
