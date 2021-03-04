#define BOOST_TEST_DYN_LINK

#include <boost/test/unit_test.hpp>
#include "../src/header.cpp"

BOOST_AUTO_TEST_SUITE(header_test)

    BOOST_AUTO_TEST_CASE(checkMagicNumber_returnsTrueWithCorrectMagicNum)
    {
        static constexpr unsigned char magicNumber[] = {0x00, 0x61, 0x73, 0x6D};

        bool isCorrect = antiwasm::checkMagicNumber(magicNumber);

        BOOST_ASSERT(isCorrect);
    }

    BOOST_AUTO_TEST_CASE(checkMagicNumber_returnsFalseWithIncorrectMagicNum)
    {
        static constexpr unsigned char notMagicNumber[] = {0x00, 0x00, 0x00, 0x00};

        bool isCorrect = antiwasm::checkMagicNumber(notMagicNumber);

        BOOST_CHECK_EQUAL(isCorrect, false);
    }

    BOOST_AUTO_TEST_CASE(checkVersion_correct)
    {
        static constexpr unsigned char version1_0[] = {0x01, 0x00, 0x00, 0x00};

        bool isCorrect = antiwasm::checkVersion(version1_0);

        BOOST_ASSERT(isCorrect);
    }

    BOOST_AUTO_TEST_CASE(checkVersion_incorrect)
    {
        static constexpr unsigned char incorrectVersion[] = {0x00, 0x00, 0x00, 0x00};

        bool isCorrect = antiwasm::checkVersion(incorrectVersion);

        BOOST_CHECK_EQUAL(isCorrect, false);
    }


BOOST_AUTO_TEST_SUITE_END() //driver_test
