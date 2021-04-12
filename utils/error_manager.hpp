#ifndef ANTIWASM_ERROR_MANAGER_HPP
#define ANTIWASM_ERROR_MANAGER_HPP

#include <memory>
#include <section.hpp>

namespace antiwasm {
enum ErrorTypes {
  unknown,
  incorrectHeader,
  unrecognizedVersion,
  wrongSectionId
};

enum ErrorSeverity { fatal, warning };

struct ParsingError {
  ErrorSeverity severity;
  ErrorTypes errorType;
  Section *section;
  unsigned int elementIndex;
};

std::shared_ptr<ParsingError> generateError(ErrorSeverity severity,
                                            ErrorTypes errorType,
                                            Section *section,
                                            unsigned int index);

} // namespace antiwasm

#endif // ANTIWASM_ERROR_MANAGER_HPP