#include "code.hpp"

namespace antiwasm {

Code::Code(uint32_t size_, Func func_) : size(size_), func(std::move(func_)) {
  if(func.hasError()) {
    BOOST_LOG_TRIVIAL(debug) << "[code] Has error invalidFuncAtCode";
    auto error = generateError(fatal, invalidFuncAtCode, 0);
    addError(error);
  } else if (size_ != func_.getNBytes()) {
    BOOST_LOG_TRIVIAL(debug) << "[code] Has error notMatchingSizeOfFuncAtCode";
    auto error = generateError(fatal, notMatchingSizeOfFuncAtCode, 0);
    addError(error);
  }
}

std::string Code::getAsText() const { return nullptr; }

Code parseCode(const uint8_t *codeContent) {
  uint32_t n = transformLeb128ToUnsignedInt32(codeContent);
  size_t pos = sizeOfLeb128(codeContent);

  Func func = parseFunc(codeContent + pos);
  pos += func.getNBytes();

  Code code{n, func};
  code.setNBytes(pos);
  return code;
}

} // namespace antiwasm
