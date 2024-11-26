cmake_minimum_required(VERSION 3.10)

project(Learn)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${CMAKE_SOURCE_DIR}/../3thPart)

file(GLOB_RECURSE SOURCES "src/*.cpp")

add_executable(program ${SOURCES})
