#include "numtype.hpp"

namespace antiwasm {
Numtype parseNumType(const uint8_t numtypeContent) {
  if (numtypeContent == i32) {
    return i32;
  } else if (numtypeContent == i64) {
    return i64;
  } else if (numtypeContent == f32) {
    return f32;
  } else if (numtypeContent == f64) {
    return f64;
  } else {
    // TODO error message
    return invalid_numtype;
  }
}

void displayNumtype(Numtype numtype) {
  switch (numtype) {
  case i32:
    cout << "i32";
    break;
  case i64:
    cout << "i64";
    break;
  case f32:
    cout << "f32";
    break;
  case f64:
    cout << "f64";
    break;
  case invalid_numtype:
    cout << "error.numtype";
    break;
  }
}
} // namespace antiwasm
