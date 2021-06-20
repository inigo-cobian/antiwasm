#include "reftype.hpp"

using namespace std;
namespace antiwasm {

Reftype parseReftype(const uint8_t reftype) {
  if (reftype == funref) {
    return funref;
  } else if (reftype == externref) {
    return externref;
  } else {
    // TODO error message
    return invalid_reftype;
  }
}

string getReftypeAsText(Reftype reftype) {
  switch (reftype) {
  case funref:
    return "funref";
  case externref:
    return "externref";
  default:
    return "error.reftype";
  }
}
} // namespace antiwasm
