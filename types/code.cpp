#include "code.hpp"

namespace antiwasm {

Code::Code(uint32_t size_, Func func_) : size(size_), func(std::move(func_)) {}

std::string Code::getAsText() const { return nullptr; }

Code parseCode(const uint8_t *codeContent) { return Code{0, parseFunc(nullptr)}; }

} // namespace antiwasm
