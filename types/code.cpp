#include "code.hpp"

namespace antiwasm {

Code::Code(uint32_t size_, Func func_) : size(size_), func(std::move(func_)) {
  if (func.hasError()) {
    BOOST_LOG_TRIVIAL(debug) << "[code] Has error invalidFuncAtCode";
    auto error = generateError(fatal, invalidFuncAtCode, 0);
    addError(error);
  } else if (size_ != func_.getNBytes()) {
    BOOST_LOG_TRIVIAL(debug) << "[code] Has error notMatchingSizeOfFuncAtCode";
    auto error = generateError(fatal, notMatchingSizeOfFuncAtCode, 0);
    addError(error);
  }
}

std::string Code:: getAsText(size_t index) const {
  std::stringstream codeAsText;

  codeAsText << "( code $" << index << " size=" << size << "\n"
             << func.getAsText() << "\n)\n";

  return codeAsText.str();
}

Code parseCode(const uint8_t *codeContent) {
  uint32_t n = transformLeb128ToUnsignedInt32(codeContent);
  size_t pos = sizeOfLeb128(codeContent);
  BOOST_LOG_TRIVIAL(debug) << "[code] Has n [" << n << "] with size [" << pos << "]";

  Func func = parseFunc(codeContent + pos);
  pos += func.getNBytes();

  Code code{n, func};
  code.setNBytes(pos);
  return code;
}

} // namespace antiwasm
