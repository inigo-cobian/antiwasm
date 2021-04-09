#ifndef ANTIWASM_ERROR_HPP
#define ANTIWASM_ERROR_HPP

#include <section.hpp>

namespace antiwasm {
    enum error_types {
        unknown,
        incorrectHeader,
        unrecognizedVersion,
        wrongSectionId
    };

    enum error_severity {
        fatal,
        warning
    };

    struct Error {
        Section *section;
        unsigned int elementIndex;
        error_types errorType;
        error_severity severity;
    };
}

#endif //ANTIWASM_ERROR_HPP
