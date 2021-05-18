#include "contentBlock.hpp"

namespace antiwasm {

void ContentBlock::addError(const std::shared_ptr<ErrorAtWasm> &errorAtWasm) { errors_.push_back(errorAtWasm); }

bool ContentBlock::hasError() { return !errors_.empty(); }

std::shared_ptr<ErrorAtWasm> ContentBlock::getError() {
  if (errors_.empty()) {
    return generateNoError();
  }
  return errors_.front();
}
void ContentBlock::displayContentBytes() const {
  for (int i = 0; i < nBytes; i++) {
    std::cout << std::hex << contentBytes.get()[i];
  }
}

} // namespace antiwasm