#ifndef SECTION_HPP
#define SECTION_HPP

#include <iostream>
#include "section_index.hpp"

class Section {
protected:
    antiwasm::SectionId sectionId_;
    int size_;
    unsigned char *content_;
    int initialPos_;
public:
    /**
     * Constructor
     * @param sectionId
     * @param size
     * @param content
     * @param initialPos
     */
    Section(antiwasm::SectionId sectionId, int size, unsigned char *content, int initialPos);

    /**
     * Destructor
     */
    ~Section() {}

    /**
     * Gets the Id of the section.
     * @return The section Id.
     */
    antiwasm::SectionId getSectionId();

    /**
     * Gets the size of the section in bytes.
     * @return The size of the section.
     */
    int getSize();

    /**
     * Gets the content of the section as bytes.
     * @return The content of the section as bytes
     */
    unsigned char *getContent();

    /**
     * Gets the initial position of the section inside the module.
     * @return The initial position inside the module.
     */
    int getInitialPos();

    /** TODO a different version for each section type
     * Displays the general information of the section.
     */
    void displaySectionInfo();
};

#endif //SECTION_HPP
