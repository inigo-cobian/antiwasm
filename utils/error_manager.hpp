#ifndef ANTIWASM_ERROR_MANAGER_HPP
#define ANTIWASM_ERROR_MANAGER_HPP

#include <memory>

namespace antiwasm {
enum ErrorTypes {
  unknown,

  // Driver
  driverNotParsing,

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
  unrecognizedHeaderAtImportDesc,
  unrecognizedTypeIdxAtImportDesc, // TODO use
  unrecognizedTabletypeAtImportDesc,
  unrecognizedMemtypeAtImportDesc,
  unrecognizedGlobaltypeAtImportDesc,

  // Data
  unrecognizedDataHeader,
  invalidExpressionAtData,
  invalidMemidxAtData, // TODO

  // Export
  invalidExportDescAtExport,

  // Code
  unrecognizedValtypeAtLocals,
  invalidLocalAtFunc,
  invalidExprAtFunc,
  invalidFuncAtCode,
  notMatchingSizeOfFuncAtCode,

  // UTF8
  unrecognizedUTF8LeadingByte,
  unrecognizedUTF8ContByte,

  // Instructions
  unrecognizedInstruction,
  unrecognizedDoubleByteInstruction,
  unlinkedElseAtInstruction,
  invalidInstructionAtBlock,
  unrecognizedValtypeAtSelectInstr,

  // Expression
  invalidInstructionAtExpression,
  invalidElemkindAtElement,

  // Element
  invalidHeaderAtElement,

  // Sections
  invalidDataAtDatasec,
  invalidCodeAtCodeSec,
  invalidElementAtElemSec,
  invalidExportAtExportSec
};

enum ErrorSeverity { fatal, warning, noError };

struct ErrorAtWasm {
  ErrorSeverity severity;
  ErrorTypes errorType;
  unsigned int elementIndex;
};

/**
 * Generates an error according to the parameters provided.
 * @param severity
 * @param errorType
 * @param index
 * @return
 */
std::shared_ptr<ErrorAtWasm> generateError(ErrorSeverity severity, ErrorTypes errorType, unsigned int index);

/**
 * Generates and returns a "No error".
 * Used to represent the absence of error.
 * @return
 */
std::shared_ptr<ErrorAtWasm> generateNoError();

} // namespace antiwasm

#endif // ANTIWASM_ERROR_MANAGER_HPP
