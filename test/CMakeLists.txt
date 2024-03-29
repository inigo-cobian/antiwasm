#Boost test setup
set(Boost_USE_STATIC_LIBS OFF)
find_package(Boost REQUIRED COMPONENTS unit_test_framework)
include_directories(${Boost_INCLUDE_DIRS})

file(GLOB TESTS "*.cpp")
file(GLOB INSTRUCTIONS_TESTS "instructions/*.cpp")
file(GLOB MODULES_TESTS "modules/*.cpp")
file(GLOB SCANNER_TESTS "scanner/*.cpp")
file(GLOB TYPES_TESTS "types/*.cpp")
file(GLOB UTILS_TEST "utils/*.cpp")

add_executable(Boost_Tests_run ${TESTS}
        ${INSTRUCTIONS_TESTS} ${MODULES_TESTS} ${SCANNER_TESTS} ${TYPES_TESTS} ${UTILS_TEST})

target_link_libraries(Boost_Tests_run pthread boost_log ${Boost_LIBRARIES})
