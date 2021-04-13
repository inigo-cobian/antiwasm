#ifndef ANTIWASM_ERROR_MANAGER_HPP
#define ANTIWASM_ERROR_MANAGER_HPP

#include <memory>

namespace antiwasm {
enum ErrorTypes {
  unknown,
  unrecognizedHeader,
  unrecognizedVersion,
  wrongSectionId,

  unrecognizedNumtype,
  unrecognizedReftype,
  unrecognizedValtype,
  unrecognizedResulttype_AtValtype,
  unrecognizedFunctype_AtHeader,
  unrecognizedFunctype_AtRT1,
  unrecognizedFunctype_AtRT2,
  unrecognizedLimit_AtHeader,
  unrecognizedLimit_MinGreaterThanMax,
  unrecognizedTabletype_AtReftype,
  unrecognizedTabletype_AtLimit_Header,
  unrecognizedTabletype_AtLimit_MinGreaterThanMax,
  unrecognizedTabletype_AtValtype,
  unrecognizedTabletype_AtMut
};

enum ErrorSeverity { fatal, warning };

struct ErrorAtWasm {
  ErrorSeverity severity;
  ErrorTypes errorType;
  unsigned int elementIndex;
};

std::shared_ptr<ErrorAtWasm> generateError(ErrorSeverity severity, ErrorTypes errorType, unsigned int index);

} // namespace antiwasm

#endif // ANTIWASM_ERROR_MANAGER_HPP
