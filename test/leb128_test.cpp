#define BOOST_TEST_DYN_LINK

#include <boost/test/unit_test.hpp>
#include "../utils/leb128.cpp"

BOOST_AUTO_TEST_SUITE(leb128_test)

    BOOST_AUTO_TEST_CASE(transformLeb128ToUnsignedInt32_oneByte) {
        auto *leb128Val = static_cast<uint8_t *>(malloc(sizeof(uint8_t) * 1));
        leb128Val[0] = 0b0010'1011; //43 in unsigned binary
        uint32_t expected = 43;

        auto returnVal = antiwasm::transformLeb128ToUnsignedInt32(leb128Val);

        BOOST_CHECK_EQUAL(expected, returnVal);
    }

    BOOST_AUTO_TEST_CASE(transformLeb128ToUnsignedInt32_multipleBytes) {
        auto *leb128Val = static_cast<uint8_t *>(malloc(sizeof(uint8_t) * 3));
        leb128Val[0] = 0xE5; leb128Val[1] = 0x8E; leb128Val[2] = 0x26; //8
        uint32_t expected = 8;

        auto returnVal = antiwasm::transformLeb128ToUnsignedInt32(leb128Val);

        BOOST_CHECK_EQUAL(expected, returnVal);
    }

    //TODO rest of tests
    BOOST_AUTO_TEST_CASE(sizeOfLeb128_oneByte) {
        auto *leb128Val = static_cast<uint8_t *>(malloc(sizeof(uint8_t) * 3));
        leb128Val[0] = 0b1000'0001; leb128Val[1] = 0b1110'1001; leb128Val[3] = 0b0010'1011;

        auto returnVal = antiwasm::sizeOfLeb128(leb128Val);

        BOOST_CHECK_EQUAL(3, returnVal);
    }

BOOST_AUTO_TEST_SUITE_END() //leb128_test