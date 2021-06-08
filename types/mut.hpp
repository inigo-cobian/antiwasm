#ifndef ANTIWASM_MUT_HPP
#define ANTIWASM_MUT_HPP

#include <cstdint>

enum Mut : uint8_t { const_ = 0x00, var_ = 0x01, invalid_mut = 0xAA };

namespace antiwasm {
/**
 * Gets a byte and returns the equivalent Mut.
 * Returns invalid_mut if it is not a correct value.
 * @param mutContent
 * @return
 */
Mut parseMut(const uint8_t mutContent);
} // namespace antiwasm

#endif // ANTIWASM_MUT_HPP
