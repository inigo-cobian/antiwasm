#ifndef MODULE_PARSER_HPP
#define MODULE_PARSER_HPP

#define BOOST_LOG_DYN_LINK 1

#include <iostream>
#include <boost/log/trivial.hpp>
#include <cstdint>
#include "../modules/section.hpp"
#include "../modules/memsec.hpp"
#include "../modules/tablesec.hpp"
#include "../modules/typesec.cpp"

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
     * Parses a Custom section and generates its instance.
     * @param sizeOfSection
     * @param sectionContent
     * @return The parsed Custom section.
     */
    int parseCustomSection(int sizeOfSection, uint8_t *sectionContent);

    /**
     * Parses a Type section and generates its instance.
     * @param sizeOfSection
     * @param sectionContent
     * @return The parsed Type section.
     */
    TypeSection parseTypeSection(int sizeOfSection, uint8_t *sectionContent);

    /**
     * Parses an Import section and generates its instance.
     * @param sizeOfSection
     * @param sectionContent
     * @return The parsed Import section.
     */
    int parseImportSection(int sizeOfSection, uint8_t *sectionContent);

    /**
     * Parses a Function section and generates its instance.
     * @param sizeOfSection
     * @param sectionContent
     * @return The parsed Function section.
     */
    int parseFunctionSection(int sizeOfSection, uint8_t *sectionContent);

    /**
     * Parses a Table section and generates its instance.
     * @param sizeOfSection
     * @param sectionContent
     * @return The parsed Table section.
     */
    TableSection parseTableSection(int sizeOfSection, uint8_t *sectionContent);

    /**
     * Parses a Memory section and generates its instance.
     * @param sizeOfSection
     * @param sectionContent
     * @return The parsed Memory section.
     */
    MemorySection parseMemorySection(int sizeOfSection, uint8_t *sectionContent);

    /**
     * Parses a Global section and generates its instance.
     * @param sizeOfSection
     * @param sectionContent
     * @return The parsed Global section.
     */
    int parseGlobalSection(int sizeOfSection, uint8_t *sectionContent);

    /**
     * Parses an Export section and generates its instance.
     * @param sizeOfSection
     * @param sectionContent
     * @return The parsed Export section.
     */
    int parseExportSection(int sizeOfSection, uint8_t *sectionContent);

    /**
     * Parses a Start section and generates its instance.
     * @param sizeOfSection
     * @param sectionContent
     * @return The parsed Start section.
     */
    int parseStartSection(int sizeOfSection, uint8_t *sectionContent);

    /**
     * Parses an Element section and generates its instance.
     * @param sizeOfSection
     * @param sectionContent
     * @return The parsed Element section.
     */
    int parseElementSection(int sizeOfSection, uint8_t *sectionContent);

    /**
     * Parses a Code section and generates its instance.
     * @param sizeOfSection
     * @param sectionContent
     * @return The parsed Code section.
     */
    int parseCodeSection(int sizeOfSection, uint8_t *sectionContent);

    /**
     * Parses a Data section and generates its instance.
     * @param sizeOfSection
     * @param sectionContent
     * @return The parsed Data section.
     */
    int parseDataSection(int sizeOfSection, uint8_t *sectionContent);
}

#endif
