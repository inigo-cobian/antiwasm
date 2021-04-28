#ifndef SECTION_PARSER_HPP
#define SECTION_PARSER_HPP

#define BOOST_LOG_DYN_LINK 1

#include "contentBlock.hpp"
#include "importsec.hpp"
#include "leb128.hpp"
#include "memsec.hpp"
#include "section.hpp"
#include "tablesec.hpp"
#include "typesec.hpp"
#include <boost/log/trivial.hpp>
#include <cstdint>
#include <iostream>

namespace antiwasm {
/**
 * Generates a section with the given Id and returns it as an object.
 * @param sectionId
 * @param sectionSize
 * @param sectionContent
 * @param sectionPos
 * @return The parsed section.
 */
Section parseNextSection(uint8_t sectionId, int sectionSize, uint8_t *sectionContent, int sectionPos);

/**
 * Parses a CustomId section and generates its instance.
 * @param sizeOfSection
 * @param sectionContent
 * @return The parsed Custom section.
 */
int parseCustomSection(int sizeOfSection, uint8_t *sectionContent);

/**
 * Parses a TypeId section and generates its instance.
 * @param sizeOfSection
 * @param sectionContent
 * @return The parsed Type section.
 */
TypeSection parseTypeSection(int sizeOfSection, uint8_t *sectionContent);

/**
 * Parses an ImportId section and generates its instance.
 * @param sizeOfSection
 * @param sectionContent
 * @return The parsed Import section.
 */
ImportSection parseImportSection(int sizeOfSection, uint8_t *sectionContent);

/**
 * Parses a FunctionId section and generates its instance.
 * @param sizeOfSection
 * @param sectionContent
 * @return The parsed Function section.
 */
int parseFunctionSection(int sizeOfSection, uint8_t *sectionContent);

/**
 * Parses a TableId section and generates its instance.
 * @param sizeOfSection
 * @param sectionContent
 * @return The parsed Table section.
 */
TableSection parseTableSection(int sizeOfSection, uint8_t *sectionContent);

/**
 * Parses a MemoryId section and generates its instance.
 * @param sizeOfSection
 * @param sectionContent
 * @return The parsed Memory section.
 */
MemorySection parseMemorySection(int sizeOfSection, uint8_t *sectionContent);

/**
 * Parses a GlobalId section and generates its instance.
 * @param sizeOfSection
 * @param sectionContent
 * @return The parsed Global section.
 */
int parseGlobalSection(int sizeOfSection, uint8_t *sectionContent);

/**
 * Parses an ExportId section and generates its instance.
 * @param sizeOfSection
 * @param sectionContent
 * @return The parsed Export section.
 */
int parseExportSection(int sizeOfSection, uint8_t *sectionContent);

/**
 * Parses a StartId section and generates its instance.
 * @param sizeOfSection
 * @param sectionContent
 * @return The parsed Start section.
 */
int parseStartSection(int sizeOfSection, uint8_t *sectionContent);

/**
 * Parses an ElementId section and generates its instance.
 * @param sizeOfSection
 * @param sectionContent
 * @return The parsed Element section.
 */
int parseElementSection(int sizeOfSection, uint8_t *sectionContent);

/**
 * Parses a CodeId section and generates its instance.
 * @param sizeOfSection
 * @param sectionContent
 * @return The parsed Code section.
 */
int parseCodeSection(int sizeOfSection, uint8_t *sectionContent);

/**
 * Parses a DataId section and generates its instance.
 * @param sizeOfSection
 * @param sectionContent
 * @return The parsed Data section.
 */
int parseDataSection(int sizeOfSection, uint8_t *sectionContent);
} // namespace antiwasm

#endif // SECTION_PARSER_HPP
