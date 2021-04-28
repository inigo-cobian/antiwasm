#include "functype.hpp"

namespace antiwasm {

Functype parseFunctype(const uint8_t *funcTypeContent) {
  Functype functype;
  BOOST_LOG_TRIVIAL(debug) << "[Functype] Parsing a new Functype";
  if (funcTypeContent[0] != FUNCTYPE_HEADER) {
    auto error = generateError(fatal, unrecognizedHeaderAtFunctype, 0);
    functype.addError(error);
    BOOST_LOG_TRIVIAL(debug) << "[Functype] Incorrect header";
    cout << "Functype header not found: " << hex << (unsigned int)funcTypeContent[0] << endl;
    return functype;
  }

  BOOST_LOG_TRIVIAL(debug) << "[Functype] Parsing first parameter";
  functype.parameterType = parseResulttype(&funcTypeContent[BYTES_HEADER_FUNCTYPE]);
  if (functype.parameterType.hasError()) {
    auto error = generateError(fatal, unrecognizedRT1Functype, 0);
    functype.addError(error);
    cout << "ErrorId at functype.parameterType" << endl;
    return functype;
  }

  BOOST_LOG_TRIVIAL(debug) << "[Functype] Parsing second parameter";
  auto indexReturnType = BYTES_HEADER_FUNCTYPE + functype.parameterType.getNBytes();
  functype.returnType = parseResulttype(&funcTypeContent[indexReturnType]);
  if (functype.returnType.hasError()) {
    auto error = generateError(fatal, unrecognizedRT2Functype, 0);
    functype.addError(error);
    cout << "ErrorId at functype.returnType" << endl;
  }
  functype.setNBytes( BYTES_HEADER_FUNCTYPE + functype.parameterType.getNBytes() + functype.returnType.getNBytes() );
  BOOST_LOG_TRIVIAL(debug) << "[Functype] nBytes: " << functype.getNBytes();

  return functype;
}
} // namespace antiwasm