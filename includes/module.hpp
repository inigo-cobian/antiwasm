#ifndef ANTIWASM_MODULE_HPP
#define ANTIWASM_MODULE_HPP

#include <map>
#include "section.hpp"

class Module {
private:
    int size_;
    std::map<const antiwasm::SectionId, Section> sections_;
public:
    /**
     * Constructor
     * @param size
     */
    Module(int size);

    /**
     * Destructor
     */
    ~Module() { /*TODO*/ }

    /**
     * Returns the size of the file
     * @return the size of the module in bytes
     */
    int getSize();

    /**
     * Adds a section to the module.
     * @param section that has been parsed.
     */
    void addSection(Section section); //TODO check if a return value is interesting

    /**
     * Gets the section with the given Id.
     * @param sectionId
     * @return The existing section. A section with Error id if it does not exist.
     */
    Section getSection(antiwasm::SectionId sectionId);

    /**
     * Checks if the section with the given Id exists.
     * @param sectionId
     * @return true if the section exists, false if it does not.
     */
    bool containsSection(antiwasm::SectionId sectionId);
};

#endif //ANTIWASM_MODULE_HPP
