#define BOOST_TEST_DYN_LINK

#include <boost/test/unit_test.hpp>
#include "../types/globaltype.cpp"

BOOST_AUTO_TEST_SUITE(globaltype_test)

    BOOST_AUTO_TEST_CASE(parseGlobaltype_caseCorrect) {
        auto *globaltypeContent = static_cast<uint8_t *>(malloc(sizeof(uint8_t) * 2));
        globaltypeContent[0] = Numtype::i32; // Valid valtype
        globaltypeContent[1] = Mut::const_;

        auto returnGlobaltype = antiwasm::parseGlobaltype(globaltypeContent);

        BOOST_CHECK_EQUAL(false, returnGlobaltype.error);
    }

    BOOST_AUTO_TEST_CASE(parseReftype_caseInvalidValtype) {
        auto *globaltypeContent = static_cast<uint8_t *>(malloc(sizeof(uint8_t) * 2));
        globaltypeContent[0] = 0xCA; // Invalid value
        globaltypeContent[1] = Mut::const_; // Should be ignored

        auto returnGlobaltype = antiwasm::parseGlobaltype(globaltypeContent);

        BOOST_CHECK_EQUAL(true, returnGlobaltype.error);
    }

    BOOST_AUTO_TEST_CASE(parseReftype_caseInvalidMut) {
        auto *globaltypeContent = static_cast<uint8_t *>(malloc(sizeof(uint8_t) * 2));
        globaltypeContent[0] = Numtype::i32; // Valid valtype
        globaltypeContent[1] = 0xCA; // Invalid value

        auto returnGlobaltype = antiwasm::parseGlobaltype(globaltypeContent);

        BOOST_CHECK_EQUAL(true, returnGlobaltype.error);
    }


BOOST_AUTO_TEST_SUITE_END() //globaltype_test
