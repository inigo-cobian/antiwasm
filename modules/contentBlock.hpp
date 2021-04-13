#ifndef ANTIWASM_CONTENT_BLOCK_HPP
#define ANTIWASM_CONTENT_BLOCK_HPP

#include "error_manager.hpp"
#include <vector>

namespace antiwasm {

class ContentBlock {
protected:
  //TODO store bytes
  std::vector<std::shared_ptr<ErrorAtWasm>> errors_;

public:
  /**
   * Adds a new error to the error_ vector.
   * @param pointer to ErrorAtWasm
   */
  void addError(std::shared_ptr<ErrorAtWasm> errorAtWasm);
};

} // namespace antiwasm
#endif // ANTIWASM_CONTENT_BLOCK_HPP
