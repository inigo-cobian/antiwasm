#include "globaltype.hpp"

namespace antiwasm {
Globaltype parseGlobaltype(const uint8_t *globaltypeContent) {
  Globaltype globaltype{};
  globaltype.valtype = parseValtype(globaltypeContent[0]);
  if (globaltype.valtype.hasError()) {
    globaltype.error = true;
    return globaltype;
  }
  globaltype.mut = parseMut(globaltypeContent[1]);
  if (globaltype.mut == invalid_mut) {
    globaltype.error = true;
  }
  return globaltype;
}
} // namespace antiwasm
