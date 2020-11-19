cmake_minimum_required(VERSION 3.1.0)
set (CMAKE_CXX_STANDARD 17)
project (antiwasm)

include_directories(src)

# Boost
find_package(Boost 1.70 REQUIRED COMPONENTS filesystem)
message(STATUS "Boost version: ${Boost_VERSION}")
add_definitions(${Boost_LIB_DIAGNOSTIC_DEFINITIONS})

file(GLOB SOURCES "src/*.cpp")

add_executable(antiwasm ${SOURCES})


target_link_libraries (antiwasm pthread boost_log)