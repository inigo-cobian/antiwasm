#include "resulttype.hpp"

namespace antiwasm {
Resulttype parseResulttype(const uint8_t *resultTypeContent) {
  Resulttype resulttype;
  BOOST_LOG_TRIVIAL(debug) << "[Resulttype] Parsing a new Resulttype";

  auto elementsInResulttype = transformLeb128ToUnsignedInt32(resultTypeContent);
  BOOST_LOG_TRIVIAL(debug) << "[Resulttype] Elements in Resulttype: " << elementsInResulttype;

  auto pointer = sizeOfLeb128(resultTypeContent);
  for (auto i = 0; i < elementsInResulttype; i++) {
    BOOST_LOG_TRIVIAL(debug) << "[Resulttype] Parsing a new Valtype for Resulttype";
    auto elementType = resultTypeContent[pointer];
    Valtype valtype = parseValtype(elementType);
    resulttype.valtypeVector.push_back(valtype);

    if (valtype.hasError()) {
      BOOST_LOG_TRIVIAL(error) << "[Resulttype] Incorrect Valtype with value: " << elementType;
      auto error = generateError(fatal, unrecognizedValtypeAtResulttype, resulttype.valtypeVector.size());
      resulttype.addError(error);
    }
    pointer++;
  }
  resulttype.setNBytes( sizeOfLeb128(resultTypeContent) + elementsInResulttype );
  BOOST_LOG_TRIVIAL(debug) << "[Resulttype] nBytes: " << resulttype.getNBytes();

  return resulttype;
}

} // namespace antiwasm
