#ifndef ANTIWASM_EXPRESSION_PARSER_HPP
#define ANTIWASM_EXPRESSION_PARSER_HPP

#define BOOST_LOG_DYN_LINK 1

#include <boost/log/trivial.hpp>
#include <cstdint>
#include "../includes/driver.hpp"
#include "../includes/instruction.hpp"
#include "../includes/const.hpp"

namespace antiwasm {
    void parseInstr(const uint8_t *instruction, int &pointer);

    void parseExpression(uint8_t instruction);
}

#endif //ANTIWASM_EXPRESSION_PARSER_HPP
