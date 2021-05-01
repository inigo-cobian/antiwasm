#ifndef ANTIWASM_REFTYPE_HPP
#define ANTIWASM_REFTYPE_HPP

#include <cstdint>
#include <iostream>

namespace antiwasm {

const auto REFTYPE_SIZE = 1;

enum Reftype : uint32_t { funref = 0x70, externref = 0x6F, invalid_reftype = 0xFF };

/**
 * Parses and returns the reftype value.
 * Returns invalid_reftype if it is not a correct value.
 * @param reftype
 * @return
 */
Reftype parseReftype(uint8_t reftype);

void displayReftype(Reftype reftype);

std::string getReftypeAsText(Reftype reftype);

} // namespace antiwasm

#endif // ANTIWASM_REFTYPE_HPP
