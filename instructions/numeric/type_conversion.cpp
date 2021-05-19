#include "type_conversion.hpp"

namespace antiwasm {
TypeConversion::TypeConversion(const uint8_t *content) {
  instructionCode = static_cast<InstructionSet>(content[0]);
  nBytes = 1;
}
} // namespace antiwasm