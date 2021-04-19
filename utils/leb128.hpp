#ifndef ANTIWASM_LEB128_HPP
#define ANTIWASM_LEB128_HPP

#define BOOST_LOG_DYN_LINK 1

#include <boost/log/trivial.hpp>
#include <cstdint>

namespace antiwasm {
/**
 * Receives a signed LEB128 and returns the equivalent signed int of 32 bits.
 * @param leb128
 * @return signed int 32 bits
 */
int32_t transformLeb128ToSignedInt32(const uint8_t *leb128);

/**
 * Receives a signed LEB128 and returns the equivalent signed int of 64 bits.
 * @param leb128
 * @return signed int 64 bits
 */
int64_t transformLeb128ToSignedInt64(const uint8_t *leb128);

/**
 * Receives a LEB128 and returns the equivalent unsigned int of 32 bits.
 * @param leb128
 * @return unsigned int 32 bits
 */
uint32_t transformLeb128ToUnsignedInt32(const uint8_t *leb128);

/**
 * Receives a LEB128 and returns the equivalent unsigned int of 64 bits.
 * @param leb128
 * @return unsigned int 64 bits
 */
uint64_t transformLeb128ToUnsignedInt64(const uint8_t *leb128);

/**
 * Reads the LEB128 and returns the number of bytes it occupies.
 * @param leb128
 * @return bytes occupied by the LEB128 number
 */
int sizeOfLeb128(const uint8_t *leb128);
} // namespace antiwasm

#endif // ANTIWASM_LEB128_HPP
