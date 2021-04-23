#ifndef ANTIWASM_IMPORT_HPP
#define ANTIWASM_IMPORT_HPP

#include "contentBlock.hpp"
#include "importDesc.hpp"
#include "nameParser.hpp"

namespace antiwasm {

struct Import {
  UTF8Name moduleName;
  UTF8Name componentName;
  ImportDesc importDesc;
};

Import parseImport(const uint8_t *importContent);

} // namespace antiwasm

#endif // ANTIWASM_IMPORT_HPP
