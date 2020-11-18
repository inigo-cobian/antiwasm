cmake_minimum_required(VERSION 2.8.9)
set (CMAKE_CXX_STANDARD 17)
project (antiwasm)

include_directories(src)

file(GLOB SOURCES "src/*.cpp")

add_executable(antiwasm ${SOURCES})