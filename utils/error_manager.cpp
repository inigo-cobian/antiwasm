#include "error_manager.hpp"

namespace antiwasm {
std::shared_ptr<ParsingError> generateError(ErrorSeverity severity,
                                            ErrorTypes errorType,
                                            Section *section,
                                            unsigned int index) {
  auto generatedError = std::make_shared<ParsingError>();
  generatedError->severity = severity;
  generatedError->errorType = errorType;
  generatedError->section = section;
  generatedError->elementIndex = index;

  return generatedError;
}
} // namespace antiwasm