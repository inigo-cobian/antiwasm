#ifndef SECTION_PARSER_HPP
#define SECTION_PARSER_HPP

#define BOOST_LOG_DYN_LINK 1

#include "codesec.hpp"
#include "contentBlock.hpp"
#include "datasec.hpp"
#include "displayer.hpp"
#include "elemsec.hpp"
#include "exportsec.hpp"
#include "funcsec.hpp"
#include "globalsec.hpp"
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
std::shared_ptr<Section> parseNextSection(uint8_t sectionId, int sectionSize, uint8_t *sectionContent, int sectionPos);

/**
 * Parses a Custom section and generates its instance.
 * @param sizeOfSection
 * @param sectionContent
 * @return The parsed Custom section.
 */
int parseCustomSection(int sizeOfSection, uint8_t *sectionContent, int sectionPos);

/**
 * Parses a TypeId section and generates its instance.
 * @param sizeOfSection
 * @param sectionContent
 * @return The parsed Type section.
 */
TypeSection parseTypeSection(int sizeOfSection, uint8_t *sectionContent, int sectionPos);

/**
 * Parses an Import section and generates its instance.
 * @param sizeOfSection
 * @param sectionContent
 * @return The parsed Import section.
 */
ImportSection parseImportSection(int sizeOfSection, uint8_t *sectionContent, int sectionPos);

/**
 * Parses a Function section and generates its instance.
 * @param sizeOfSection
 * @param sectionContent
 * @return The parsed Function section.
 */
FuncSection parseFunctionSection(int sizeOfSection, uint8_t *sectionContent, int sectionPos);

/**
 * Parses a TableId section and generates its instance.
 * @param sizeOfSection
 * @param sectionContent
 * @return The parsed Table section.
 */
TableSection parseTableSection(int sizeOfSection, uint8_t *sectionContent, int sectionPos);

/**
 * Parses a Memory section and generates its instance.
 * @param sizeOfSection
 * @param sectionContent
 * @return The parsed Memory section.
 */
MemorySection parseMemorySection(int sizeOfSection, uint8_t *sectionContent, int sectionPos);

/**
 * Parses a Global section and generates its instance.
 * @param sizeOfSection
 * @param sectionContent
 * @return The parsed Global section.
 */
GlobalSection parseGlobalSection(int sizeOfSection, uint8_t *sectionContent, int sectionPos);

/**
 * Parses an Export section and generates its instance.
 * @param sizeOfSection
 * @param sectionContent
 * @return The parsed Export section.
 */
ExportSection parseExportSection(int sizeOfSection, uint8_t *sectionContent, int sectionPos);

/**
 * Parses a Start section and generates its instance.
 * @param sizeOfSection
 * @param sectionContent
 * @return The parsed Start section.
 */
int parseStartSection(int sizeOfSection, uint8_t *sectionContent, int sectionPos);

/**
 * Parses an Element section and generates its instance.
 * @param sizeOfSection
 * @param sectionContent
 * @return The parsed Element section.
 */
ElementSection parseElementSection(int sizeOfSection, uint8_t *sectionContent, int sectionPos);

/**
 * Parses a Code section and generates its instance.
 * @param sizeOfSection
 * @param sectionContent
 * @return The parsed Code section.
 */
CodeSection parseCodeSection(int sizeOfSection, uint8_t *sectionContent, int sectionPos);

/**
 * Parses a Data section and generates its instance.
 * @param sizeOfSection
 * @param sectionContent
 * @return The parsed Data section.
 */
DataSection parseDataSection(int sizeOfSection, uint8_t *sectionContent, int sectionPos);
} // namespace antiwasm

#endif // SECTION_PARSER_HPP
