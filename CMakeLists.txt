cmake_minimum_required(VERSION 3.1.0)
set(CMAKE_CXX_STANDARD 20)
project(antiwasm)

#codecov.io for code coverage
set(--coverage)

include_directories(init instructions modules scanner types utils)
include_directories(instructions/const)

# Boost (logging + unit test)
find_package(Boost 1.70 REQUIRED COMPONENTS filesystem)
message(STATUS "Boost version: ${Boost_VERSION}")
add_definitions(${Boost_LIB_DIAGNOSTIC_DEFINITIONS})
find_package(Boost COMPONENTS program_options REQUIRED)

#Testing subdirectory
add_subdirectory(test)

file(GLOB INIT "init/*.cpp")
file(GLOB INSTRUCTIONS "instructions/*.cpp")
file(GLOB MODULES "modules/*.cpp")
file(GLOB SCANNER "scanner/*.cpp")
file(GLOB TYPES "types/*.cpp")
file(GLOB UTILS "utils/*.cpp")

file(GLOB CONST "instructions/const/*.cpp")
file(GLOB VARIABLE "instructions/variable/*.cpp")

add_executable(antiwasm ${INIT} ${INSTRUCTIONS} ${SCANNER} ${MODULES} ${TYPES} ${UTILS}
        ${CONST} ${VARIABLE})

target_link_libraries(antiwasm pthread boost_log boost_program_options boost_thread)