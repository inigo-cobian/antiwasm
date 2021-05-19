#ifndef ANTIWASM_TYPE_CONVERSION_HPP
#define ANTIWASM_TYPE_CONVERSION_HPP

#include "instruction.hpp"

namespace antiwasm {
class TypeConversion : public Instruction {

public:
  explicit TypeConversion(const uint8_t *content);
  virtual ~TypeConversion() = default;
};
} // namespace antiwasm

#endif // ANTIWASM_TYPE_CONVERSION_HPP
