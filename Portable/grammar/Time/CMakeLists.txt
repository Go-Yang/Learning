cmake_minimum_required(VERSION 3.10)

# project name
project(portable_demo VERSION 0.0)

# set c++ stantard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 包含头文件目录
include_directories(${CMAKE_SOURCE_DIR}/include)

# 查找源文件，递归查找 src 目录下的所有 .cpp 文件，并将它们包含在 SOURCES 变量中
file(GLOB_RECURSE SOURCES "src/*.cpp")

# add source files
add_executable(program ${SOURCES})
