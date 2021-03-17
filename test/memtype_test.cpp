#define BOOST_TEST_DYN_LINK

#include <boost/test/unit_test.hpp>
#include "../src/memtype.cpp"

BOOST_AUTO_TEST_SUITE(memtype_test)

    BOOST_AUTO_TEST_CASE(parseMemType_doesNotCauseError) {
        auto *memtypeContent = static_cast<unsigned char *>(malloc(sizeof(unsigned int) * 3));
        memtypeContent[0] = limit_types::limit_min_max;
        memtypeContent[1] = 0x05;
        memtypeContent[1] = 0x08;

        Memtype returnVal = antiwasm::parseMemType(memtypeContent);

        //BOOST_ASSERT(returnVal != nullptr); TODO -> change test
    }

BOOST_AUTO_TEST_SUITE_END() //memtype_test
