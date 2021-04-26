#include "nameParser.hpp"

namespace antiwasm {

UTF8Name parseUTF8Name(const uint8_t *bytes, uint32_t nBytes) {
  // Validate
  UTF8Name utf8Name;
  utf8Name.name = string(reinterpret_cast<const char *>(bytes), nBytes);
  utf8Name.setNBytes(nBytes);
  unsigned int pos = 0;
  while (true) {

    // One byte char
    if (bytes[pos] < 0x80) {
      pos++;
      // Two byte char header = 110b'bbbb
    } else if ((bytes[pos] & 0b1110'0000) == 0b1100'0000) {
      if (!validateUTF8ContinuationByte(bytes[pos + 1])) {
        auto error = generateError(fatal, unrecognizedUTF8ContByte, pos);
        utf8Name.addError(error);
      }
      pos += 2;
      // Two byte char header = 1110'bbbb
    } else if ((bytes[pos] & 0b1111'0000) == 0b1110'0000) {
      if (!validateUTF8ContinuationByte(bytes[pos + 1]) || !validateUTF8ContinuationByte(bytes[pos + 2])) {
        auto error = generateError(fatal, unrecognizedUTF8ContByte, pos);
        utf8Name.addError(error);
      }
      pos += 3;
      // Two byte char header = 1111'0bbb
    } else if ((bytes[pos] & 0b1111'1000) == 0b1111'0000) {
      if (!validateUTF8ContinuationByte(bytes[pos + 1]) || !validateUTF8ContinuationByte(bytes[pos + 2]) ||
          !validateUTF8ContinuationByte(bytes[pos + 3])) {
        auto error = generateError(fatal, unrecognizedUTF8ContByte, pos);
        utf8Name.addError(error);
      }
      pos += 4;
    } else {
      auto error = generateError(fatal, unrecognizedUTF8LeadingByte, pos);
      utf8Name.addError(error);
    }

    if (utf8Name.hasError()) {
      return utf8Name;
    }

    if (pos >= nBytes) {
      return utf8Name;
    }
  }
}

bool validateUTF8ContinuationByte(uint8_t contByte) { return (contByte & 0b1100'0000) == 0b1000'0000; }

} // namespace antiwasm
