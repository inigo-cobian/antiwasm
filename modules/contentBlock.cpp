#include "contentBlock.hpp"

#include <utility>

namespace antiwasm {

void ContentBlock::addContentBytes(std::shared_ptr<uint8_t> ptrToContentBytes, size_t indexOfCurrentContent) {
  contentBytes = std::move(ptrToContentBytes);
  indexOfContent = indexOfCurrentContent;
}

void ContentBlock::addError(std::shared_ptr<ErrorAtWasm> errorAtWasm) { errors_.push_back(errorAtWasm); }

bool ContentBlock::hasError() { return !errors_.empty(); }

std::shared_ptr<ErrorAtWasm> ContentBlock::getError() {
  if (errors_.empty()) {
    return generateNoError();
  }
  return errors_.front();
}

} // namespace antiwasm