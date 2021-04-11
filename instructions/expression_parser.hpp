#ifndef ANTIWASM_EXPRESSION_PARSER_HPP
#define ANTIWASM_EXPRESSION_PARSER_HPP

#define BOOST_LOG_DYN_LINK 1

#include "const.hpp"
#include "driver.hpp"
#include "instruction.hpp"
#include <boost/log/trivial.hpp>
#include <cstdint>

namespace antiwasm {
void parseInstr(const uint8_t *instruction, int &pointer);

void parseExpression(uint8_t instruction);
} // namespace antiwasm

#endif // ANTIWASM_EXPRESSION_PARSER_HPP
