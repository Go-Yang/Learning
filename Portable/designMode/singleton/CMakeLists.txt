cmake_minimum_required(VERSION 3.12)

project(Learn)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(${CMAKE_SOURCE_DIR}/include)

file(GLOB_RECURSE SOURCES "src/*.cpp")

add_executable(program ${SOURCES})

find_package(Threads REQUIRED)
target_link_libraries(program PRIVATE Threads::Threads)