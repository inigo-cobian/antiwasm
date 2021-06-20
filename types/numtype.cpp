#include "numtype.hpp"

using namespace std;
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

string getNumtypeAsText(Numtype numtype) {
  switch (numtype) {
  case i32:
    return "i32";
  case i64:
    return "i64";
  case f32:
    return "f32";
  case f64:
    return "f64";
  case invalid_numtype:
  default:
    return "error.numtype";
  }
}
} // namespace antiwasm
