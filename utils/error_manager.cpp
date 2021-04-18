#include "error_manager.hpp"

namespace antiwasm {
shared_ptr<ErrorAtWasm> generateError(ErrorSeverity severity, ErrorTypes errorType, unsigned int index) {
  auto generatedError = make_shared<ErrorAtWasm>();
  generatedError->severity = severity;
  generatedError->errorType = errorType;
  generatedError->elementIndex = index;

  return generatedError;
}

shared_ptr<ErrorAtWasm> generateNoError() {
  auto generatedNoError = make_shared<ErrorAtWasm>();
  generatedNoError->severity = noError;

  return generatedNoError;
}
} // namespace antiwasm