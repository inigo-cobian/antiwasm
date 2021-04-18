#ifndef ANTIWASM_CONTENT_BLOCK_HPP
#define ANTIWASM_CONTENT_BLOCK_HPP

#include "error_manager.hpp"
#include <vector>
#include <iostream>

using namespace std;

namespace antiwasm {

class ContentBlock {
protected:
  shared_ptr<uint8_t> contentBytes;
  size_t indexOfContent;
  size_t nBytes;
  vector<shared_ptr<ErrorAtWasm>> errors_;

public:
  /**
   * Gets the pointer to the content block the current content belongs (as bytes)
   * and its position at the block.
   * @param contentBytes
   * @param indexOfContent
   */
  void addContentBytes(shared_ptr<uint8_t> ptrToContentBytes, size_t indexOfCurrentContent, size_t nBytesOfContent);

  /**
   * Adds a new error to the error_ vector.
   * @param pointer to ErrorAtWasm
   */
  void addError(const shared_ptr<ErrorAtWasm>& errorAtWasm);

  /**
   * Checks the vector of errors and returns true if there is at least one.
   * @return if the content block has any error.
   */
  bool hasError();

  /**
   * Returns the error of a content block with a single error.
   * If there is no error it returns a default error.
   * @return
   */
  shared_ptr<ErrorAtWasm> getError();

  virtual void displayError() = 0;

  /**
   * Displays the bytes of the content block in hexadecimal notation.
   */
  void displayContentBytes() const;

  virtual void displayContentInfo() = 0;
};

} // namespace antiwasm
#endif // ANTIWASM_CONTENT_BLOCK_HPP
