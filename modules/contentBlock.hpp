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

  /**
   * Gets the number of bytes of the content block
   * @return
   */
  [[nodiscard]] uint32_t getNBytes() const { return nBytes; };

  /**
   * Sets the number of bytes of the content block
   * @param p_nBytes
   */
  void setNBytes(uint32_t p_nBytes) { nBytes = p_nBytes; };

  /**
   * Adds the argument to the number of bytes of the content block
   * @param p_nBytes
   */
  void addNBytes(uint32_t p_nBytes) { nBytes += p_nBytes; };
};

} // namespace antiwasm
#endif // ANTIWASM_CONTENT_BLOCK_HPP
