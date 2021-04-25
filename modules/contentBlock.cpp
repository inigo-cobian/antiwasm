#include "contentBlock.hpp"

namespace antiwasm {

void ContentBlock::addContentBytes(shared_ptr<uint8_t> ptrToContentBytes, size_t indexOfCurrentContent,
                                   size_t nBytesOfContent) {
  contentBytes = move(ptrToContentBytes);
  indexByte = indexOfCurrentContent;
}

void ContentBlock::addError(const shared_ptr<ErrorAtWasm> &errorAtWasm) { errors_.push_back(errorAtWasm); }

bool ContentBlock::hasError() { return !errors_.empty(); }

shared_ptr<ErrorAtWasm> ContentBlock::getError() {
  if (errors_.empty()) {
    return generateNoError();
  }
  return errors_.front();
}
void ContentBlock::displayContentBytes() const {
  for (int i = 0; i < nBytes; i++) {
    cout << hex << contentBytes.get()[i];
  }
}

} // namespace antiwasm