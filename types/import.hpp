#ifndef ANTIWASM_IMPORT_HPP
#define ANTIWASM_IMPORT_HPP

#include "contentBlock.hpp"
#include "globaltype.hpp"
#include "memtype.hpp"
#include "nameParser.hpp"
#include "tabletype.hpp"
#include <cstdint>

namespace antiwasm {

enum ImportDescType : uint8_t { ImportFunc = 0x00, ImportTable = 0x01, ImportMemtype = 0x02, ImportGlobaltype = 0x03 };

union ImportDesc {
  uint32_t typeIdx;
  Tabletype tabletype;
  Memtype memtype;
  Globaltype globaltype;
};

struct Import {
  UTF8Name moduleName;
  UTF8Name componentName;
  ImportDescType importDescType;
  ImportDesc importDesc;
};

Import parseImport(const uint8_t *importContent);

} // namespace antiwasm

#endif // ANTIWASM_IMPORT_HPP
