#include "error_manager.hpp"

namespace antiwasm {
std::shared_ptr<ErrorAtWasm> generateError(ErrorSeverity severity,
                                            ErrorTypes errorType,
                                            Section *section,
                                            unsigned int index) {
  auto generatedError = std::make_shared<ErrorAtWasm>();
  generatedError->severity = severity;
  generatedError->errorType = errorType;
  generatedError->section = section;
  generatedError->elementIndex = index;

  return generatedError;
}
} // namespace antiwasm