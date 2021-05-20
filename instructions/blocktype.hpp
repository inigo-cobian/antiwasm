#ifndef ANTIWASM_BLOCKTYPE_HPP
#define ANTIWASM_BLOCKTYPE_HPP

#include "contentBlock.hpp"
#include "leb128.hpp"
#include "valtype.hpp"
#include <cstdint>

namespace antiwasm {
enum Blocktype_type { emptyBlocktype, valtypeBlocktype, typeidxBlocktype };

struct Blocktype : public ContentBlock {
  Blocktype_type type;
  Valtype valtype{};
  uint32_t typeidx{};
};

/**
 * Gets the content and generates a Blocktype.
 * Adds error if cannot complete the parsing.
 * @param blocktypeContent
 * @return
 */
Blocktype parseBlocktype(const uint8_t *blocktypeContent);
}

#endif // ANTIWASM_BLOCKTYPE_HPP
