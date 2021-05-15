#include "float_parser.hpp"

namespace antiwasm {
float transformf32ToFloat(const uint8_t *f32) {
  float f;
  uint8_t asChar[] = {f32[3], f32[2], f32[1], f32[0]};
  memcpy(&f, &asChar, 4);
  return f;
}

double transformf64ToDouble(const uint8_t *f64) {
  double d;
  uint8_t asChar[] = {f64[7], f64[6], f64[5], f64[4], f64[3], f64[2], f64[1], f64[0]};
  memcpy(&d, &asChar, 8);
  return d;
}

} // namespace antiwasm