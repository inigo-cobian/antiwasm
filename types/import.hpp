#ifndef ANTIWASM_IMPORT_HPP
#define ANTIWASM_IMPORT_HPP

#include "contentBlock.hpp"
#include "globaltype.hpp"
#include "memtype.hpp"
#include "nameParser.hpp"
#include "tabletype.hpp"
#include "leb128.hpp"
#include <cstdint>
#include <utility>

namespace antiwasm {

enum ImportDescType : uint8_t { ImportFunc = 0x00, ImportTable = 0x01, ImportMemtype = 0x02, ImportGlobaltype = 0x03 };

union ImportDesc {
  // TODO documentar que no se pueden usar smart pointers porque no se permiten non-trivial contructors
  uint32_t typeIdx;
  Tabletype* tabletype;
  Memtype* memtype;
  Globaltype* globaltype;
};

struct Import : public ContentBlock {
  UTF8Name module;
  UTF8Name name;
  ImportDescType importDescType;
  ImportDesc importDesc;

public:
  Import(UTF8Name p_module, UTF8Name p_name, ImportDescType p_importDescType, ImportDesc p_importDesc)
  : module(std::move(p_module)), name(std::move(p_name)), importDescType(p_importDescType), importDesc(p_importDesc) {}
};

Import parseImport(const uint8_t *importContent);

ImportDesc parseImportDesc(ImportDescType type, const uint8_t *importDescContent);
} // namespace antiwasm

#endif // ANTIWASM_IMPORT_HPP
