#ifndef ANTIWASM_FLOAT_PARSER_HPP
#define ANTIWASM_FLOAT_PARSER_HPP

#include <boost/log/trivial.hpp>
#include <cstdint>

namespace antiwasm {
/**
 * Receives a f32 as bytes and returns the equivalent float.
 * @param f32
 * @return value as a float
 */
float transformf32ToFloat(const uint8_t *f32);

/**
 * Receives a f64 as bytes and returns the equivalent double.
 * @param f64
 * @return value as a double
 */
double transformf64ToDouble(const uint8_t *f64);
} // namespace antiwasm

#endif // ANTIWASM_FLOAT_PARSER_HPP
