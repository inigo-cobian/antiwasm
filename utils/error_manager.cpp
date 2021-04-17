#include "error_manager.hpp"

namespace antiwasm {
std::shared_ptr<ErrorAtWasm> generateError(ErrorSeverity severity, ErrorTypes errorType, unsigned int index) {
  auto generatedError = std::make_shared<ErrorAtWasm>();
  generatedError->severity = severity;
  generatedError->errorType = errorType;
  generatedError->elementIndex = index;

  return generatedError;
}

std::shared_ptr<ErrorAtWasm> generateNoError() {
  auto generatedNoError = std::make_shared<ErrorAtWasm>();
  generatedNoError->severity = noError;

  return generatedNoError;
}
} // namespace antiwasm