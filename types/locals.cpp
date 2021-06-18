#include "locals.hpp"

namespace antiwasm {

Locals::Locals(uint32_t n_, Valtype valtype_) : n(n_), valtype(valtype_) {
  if (valtype_.hasError()) {
    BOOST_LOG_TRIVIAL(error) << "[func] Error unrecognizedValtypeAtLocals at valtype with value: " << valtype.getAsText();
    auto error = generateError(fatal, unrecognizedValtypeAtLocals, 0);
    errors_.push_back(error);
  }
}

std::string Locals::getAsText() const { return std::string(); }

Locals parseLocals(const uint8_t *localsContent) {
  uint32_t n_ = transformLeb128ToUnsignedInt32(localsContent);
  auto pos = sizeOfLeb128(localsContent);

  auto valtype_ = parseValtype(localsContent[pos]);

  Locals locals{n_, valtype_};
  locals.setNBytes(pos + 1);

  return locals;
}

} // namespace antiwasm