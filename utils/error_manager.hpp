#ifndef ANTIWASM_ERROR_MANAGER_HPP
#define ANTIWASM_ERROR_MANAGER_HPP

#include <memory>

namespace antiwasm {
enum ErrorTypes {
  unknown,
  unrecognizedHeader,
  unrecognizedVersion,
  wrongSectionId,

  unrecognizedNumtype [[maybe_unused]],
  unrecognizedReftype [[maybe_unused]],
  unrecognizedValtype,
  unrecognizedValtypeAtResulttype,
  unrecognizedHeaderAtFunctype,
  unrecognizedRT1Functype,
  unrecognizedRT2Functype,
  unrecognizedHeaderAtLimit,
  unrecognizedMinGreaterThanMaxAtLimit,
  unrecognizedReftypeAtTabletype,
  unrecognizedLimitHeaderAtTabletype,
  unrecognizedMinGreaterThanMaxLimitAtTabletype,
  unrecognizedValtypeAtGlobaltype,
  unrecognizedMutAtGlobaltype
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
