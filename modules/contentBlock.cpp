#include "contentBlock.hpp"

namespace antiwasm {

void ContentBlock::addError(std::shared_ptr<ErrorAtWasm> errorAtWasm) { errors_.push_back(errorAtWasm); }

bool ContentBlock::hasError() { return !errors_.empty(); }

std::shared_ptr<ErrorAtWasm> ContentBlock::getError() {
  return errors_.front();
}

} // namespace antiwasm