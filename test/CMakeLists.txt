#Boost test setup
set (Boost_USE_STATIC_LIBS OFF)
find_package (Boost REQUIRED COMPONENTS unit_test_framework)
include_directories (${Boost_INCLUDE_DIRS})

#include_directories (src)
#file(GLOB SOURCES "src/*.cpp")

file(GLOB TESTS "*.cpp")
add_executable (Boost_Tests_run ${TESTS} ${SOURCES})

target_link_libraries (Boost_Tests_run pthread boost_log ${Boost_LIBRARIES})
