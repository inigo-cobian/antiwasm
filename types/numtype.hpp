#ifndef ANTIWASM_NUMTYPE_HPP
#define ANTIWASM_NUMTYPE_HPP

#include <cstdint>
#include <iostream>

using namespace std;
namespace antiwasm {

enum Numtype : int32_t { i32 = 0x7F, i64 = 0x7E, f32 = 0x7D, f64 = 0x7C, invalid_numtype = 0xFF };

/**
 * Gets a byte and returns the equivalent NumType
 * Returns invalid_numtype if it is not a correct value.
 * @param numtypeContent
 * @return
 */
Numtype parseNumType(uint8_t numtypeContent);

void displayNumtype(Numtype numtype);

string getNumtypeAsText(Numtype numtype);

} // namespace antiwasm

#endif // ANTIWASM_NUMTYPE_HPP
