#ifndef ANTIWASM_CONTENT_BLOCK_HPP
#define ANTIWASM_CONTENT_BLOCK_HPP

#include "error_manager.hpp"
#include <iostream>
#include <vector>

namespace antiwasm {

class ContentBlock {
protected:
  std::shared_ptr<uint8_t> contentBytes;
  size_t indexByte;
  size_t nBytes;
  std::vector<std::shared_ptr<ErrorAtWasm>> errors_;

public:
  /**
   * Gets the pointer to the content block the current content belongs (as bytes)
   * and its position at the block.
   * @param contentBytes
   * @param indexOfContent
   */
  void addContentBytes(std::shared_ptr<uint8_t> ptrToContentBytes, size_t indexOfCurrentContent, size_t nBytesOfContent);

  /**
   * Adds a new error to the error_ vector.
   * @param pointer to ErrorAtWasm
   */
  void addError(const std::shared_ptr<ErrorAtWasm> &errorAtWasm);

  /**
   * Checks the vector of errors and returns true if there is at least one.
   * @return if the content block has any error.
   */
  bool hasError();

  /**
   * Displays the bytes of the content block in hexadecimal notation.
   */
  void displayContentBytes() const;

  /**
   * Returns the error of a content block with a single error.
   * If there is no error it returns a default error.
   * @return
   */
  std::shared_ptr<ErrorAtWasm> getError();

  [[nodiscard]] uint32_t getNBytes() const { return nBytes; };

  void setNBytes(uint32_t p_nBytes) { nBytes = p_nBytes; };
};

} // namespace antiwasm
#endif // ANTIWASM_CONTENT_BLOCK_HPP
