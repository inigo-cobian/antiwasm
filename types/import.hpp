#ifndef ANTIWASM_IMPORT_HPP
#define ANTIWASM_IMPORT_HPP

#include "contentBlock.hpp"
#include "globaltype.hpp"
#include "leb128.hpp"
#include "memtype.hpp"
#include "nameParser.hpp"
#include "tabletype.hpp"
#include <cstdint>
#include <utility>

namespace antiwasm {

static const size_t SIZE_OF_IMPORT_DESC_TYPE = 1;

enum ImportDescType : uint8_t {
  ImportFunc = 0x00,
  ImportTable = 0x01,
  ImportMemtype = 0x02,
  ImportGlobaltype = 0x03,
  invalidImportDescType = 0xFF
};

union ImportDesc {
  // TODO documentar que no se pueden usar smart pointers porque no se permiten non-trivial contructors
  uint32_t typeIdx;
  Tabletype *tabletype;
  Memtype *memtype;
  Globaltype *globaltype;
};

struct Import : public ContentBlock {
  UTF8Name module;
  UTF8Name name;
  ImportDescType importDescType{};
  ImportDesc importDesc{};

  Import(UTF8Name p_module, UTF8Name p_name, ImportDescType p_importDescType, ImportDesc p_importDesc)
      : module(std::move(p_module)), name(std::move(p_name)), importDescType(p_importDescType),
        importDesc(p_importDesc) {}

  Import(UTF8Name p_module, UTF8Name p_name) : module(std::move(p_module)), name(std::move(p_name)) {}

  void addImportDesc(ImportDescType type, const uint8_t *importDescContent);
};

ImportDescType parseImportDescType(const uint8_t importDescTypeContent);

Import parseImport(const uint8_t *importContent);
} // namespace antiwasm

#endif // ANTIWASM_IMPORT_HPP
