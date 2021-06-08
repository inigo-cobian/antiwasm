#include "locals.hpp"

namespace antiwasm {

Locals::Locals(uint32_t n_, Valtype valtype_) {}

std::string Locals::getAsText() const { return std::string(); }

Locals parseLocals(const uint8_t *localsContent) {
  return Locals{0, parseValtype(Numtype::i32)};
}

}