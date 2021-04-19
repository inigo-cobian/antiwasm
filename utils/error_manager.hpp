#ifndef ANTIWASM_ERROR_MANAGER_HPP
#define ANTIWASM_ERROR_MANAGER_HPP

#include <memory>

using namespace std;

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

enum ErrorSeverity { fatal, warning, noError };

struct ErrorAtWasm {
  ErrorSeverity severity;
  ErrorTypes errorType;
  unsigned int elementIndex;
};

shared_ptr<ErrorAtWasm> generateError(ErrorSeverity severity, ErrorTypes errorType, unsigned int index);

shared_ptr<ErrorAtWasm> generateNoError();

} // namespace antiwasm

#endif // ANTIWASM_ERROR_MANAGER_HPP
