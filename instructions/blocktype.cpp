#include "blocktype.hpp"

namespace antiwasm {
Blocktype parseBlocktype(const uint8_t *blocktypeContent) {
  Blocktype blocktype;
  if (blocktypeContent[0] == 0x40) {
    blocktype.type = emptyBlocktype;
    blocktype.setNBytes(1);
    return blocktype;
  }

  Valtype valtype = parseValtype(blocktypeContent[0]);
  if (valtype.type != valtype_error) {
    blocktype.type = valtypeBlocktype;
    blocktype.valtype = valtype;
    blocktype.setNBytes(1);
    return blocktype;
  }

  // As the value is s33, a s64 is used and then transformed into the unsigned index
  blocktype.type = typeidxBlocktype;
  blocktype.typeidx = static_cast<uint32_t>(transformLeb128ToSignedInt64(blocktypeContent));
  blocktype.setNBytes(sizeOfLeb128(blocktypeContent));
  return blocktype;
}
} // namespace antiwasm
