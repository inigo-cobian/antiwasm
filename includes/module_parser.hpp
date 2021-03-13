#ifndef MODULE_PARSER_HPP
#define MODULE_PARSER_HPP

#define BOOST_LOG_DYN_LINK 1

#include <iostream>
#include <boost/log/trivial.hpp>
#include <cstdint>
#include "section_index.hpp"
#include "../includes/section.hpp"

namespace antiwasm {
    /**
     * Generates a section with the given Id and returns it as an object.
     * @param sectionId
     * @param sectionSize
     * @param sectionContent
     * @param sectionPos
     * @return The parsed section.
     */
    Section parseNextSection(unsigned char sectionId, int sectionSize, unsigned char *sectionContent, int sectionPos);

    /**
     * Parses a Custom section and generates its instance.
     * @param sizeOfSection
     * @param sectionContent
     * @return The parsed Custom section.
     */
    int parseCustomSection(int sizeOfSection, unsigned char *sectionContent);

    /**
     * Parses a Type section and generates its instance.
     * @param sizeOfSection
     * @param sectionContent
     * @return The parsed Type section.
     */
    int parseTypeSection(int sizeOfSection, unsigned char *sectionContent);

    /**
     * Parses an Import section and generates its instance.
     * @param sizeOfSection
     * @param sectionContent
     * @return The parsed Import section.
     */
    int parseImportSection(int sizeOfSection, unsigned char *sectionContent);

    /**
     * Parses a Function section and generates its instance.
     * @param sizeOfSection
     * @param sectionContent
     * @return The parsed Function section.
     */
    int parseFunctionSection(int sizeOfSection, unsigned char *sectionContent);

    /**
     * Parses a Table section and generates its instance.
     * @param sizeOfSection
     * @param sectionContent
     * @return The parsed Table section.
     */
    int parseTableSection(int sizeOfSection, unsigned char *sectionContent);

    /**
     * Parses a Memory section and generates its instance.
     * @param sizeOfSection
     * @param sectionContent
     * @return The parsed Memory section.
     */
    int parseMemorySection(int sizeOfSection, unsigned char *sectionContent);

    /**
     * Parses a Global section and generates its instance.
     * @param sizeOfSection
     * @param sectionContent
     * @return The parsed Global section.
     */
    int parseGlobalSection(int sizeOfSection, unsigned char *sectionContent);

    /**
     * Parses an Export section and generates its instance.
     * @param sizeOfSection
     * @param sectionContent
     * @return The parsed Export section.
     */
    int parseExportSection(int sizeOfSection, unsigned char *sectionContent);

    /**
     * Parses a Start section and generates its instance.
     * @param sizeOfSection
     * @param sectionContent
     * @return The parsed Start section.
     */
    int parseStartSection(int sizeOfSection, unsigned char *sectionContent);

    /**
     * Parses an Element section and generates its instance.
     * @param sizeOfSection
     * @param sectionContent
     * @return The parsed Element section.
     */
    int parseElementSection(int sizeOfSection, unsigned char *sectionContent);

    /**
     * Parses a Code section and generates its instance.
     * @param sizeOfSection
     * @param sectionContent
     * @return The parsed Code section.
     */
    int parseCodeSection(int sizeOfSection, unsigned char *sectionContent);

    /**
     * Parses a Data section and generates its instance.
     * @param sizeOfSection
     * @param sectionContent
     * @return The parsed Data section.
     */
    int parseDataSection(int sizeOfSection, unsigned char *sectionContent);
}

#endif
