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

# MPI
find_package(MPI REQUIRED)
include_directories(${MPI_INCLUDE_PATH})
add_definitions(-DOMPI_SKIP_MPICXX)

#Testing subdirectory
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

#target_link_libraries(antiwasm pthread boost_log boost_program_options boost_thread)
target_link_libraries(antiwasm pthread boost_log boost_program_options boost_thread ${MPI_LIBRARIES})