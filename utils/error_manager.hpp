#ifndef ANTIWASM_ERROR_MANAGER_HPP
#define ANTIWASM_ERROR_MANAGER_HPP

#include <memory>

namespace antiwasm {
enum ErrorTypes {
  unknown,

  // Module
  unrecognizedHeader,
  unrecognizedVersion,
  wrongSectionId,

  // Types
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
  unrecognizedMutAtGlobaltype,

  // Imports
  unrecognizedModAtImport,
  unrecognizedNameAtImport,
  unrecognizedHeaderAtImportDesc, // TODO use
  unrecognizedTypeIdxAtImportDesc,
  unrecognizedTabletypeAtImportDesc,
  unrecognizedMemtypeAtImportDesc,
  unrecognizedGlobaltypeAtImportDesc,

  // UTF8
  unrecognizedUTF8LeadingByte,
  unrecognizedUTF8ContByte,

  // Instructions
  unrecognizedInstruction
};

enum ErrorSeverity { fatal, warning, noError };

struct ErrorAtWasm {
  ErrorSeverity severity;
  ErrorTypes errorType;
  unsigned int elementIndex;
};

std::shared_ptr<ErrorAtWasm> generateError(ErrorSeverity severity, ErrorTypes errorType, unsigned int index);

std::shared_ptr<ErrorAtWasm> generateNoError();

} // namespace antiwasm

#endif // ANTIWASM_ERROR_MANAGER_HPP
