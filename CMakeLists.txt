cmake_minimum_required(VERSION 3.19)
set(CMAKE_CXX_STANDARD 23)
project(antiwasm)

include_directories(init instructions modules scanner types utils)
include_directories(instructions/const)

# Boost via Conan CMakeDeps
find_package(Boost REQUIRED COMPONENTS filesystem program_options log log_setup thread)

# Testing subdirectory
add_subdirectory(test)

file(GLOB INIT "init/*.cpp")
file(GLOB INSTRUCTIONS "instructions/*.cpp")
file(GLOB MODULES "modules/*.cpp")
file(GLOB SCANNER "scanner/*.cpp")
file(GLOB TYPES "types/*.cpp")
file(GLOB UTILS "utils/*.cpp")

file(GLOB VARIABLE "instructions/variable/*.cpp")
file(GLOB MEMORY "instructions/memory/*.cpp")
file(GLOB NUMERIC "instructions/numeric/*.cpp")
file(GLOB CONTROL "instructions/control/*.cpp")
file(GLOB REFERENCE "instructions/reference/*.cpp")
file(GLOB TABLE "instructions/table/*.cpp")
file(GLOB PARAMETRIC "instructions/parametric/*.cpp")

add_executable(antiwasm ${INIT} ${INSTRUCTIONS} ${SCANNER} ${MODULES} ${TYPES} ${UTILS}
        ${VARIABLE} ${MEMORY} ${NUMERIC} ${CONTROL} ${REFERENCE} ${TABLE} ${PARAMETRIC})

target_link_libraries(antiwasm Boost::log Boost::log_setup Boost::program_options Boost::thread Boost::filesystem)
