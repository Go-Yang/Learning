cmake_minimum_required(VERSION 3.10)

# 项目名称
project(Program)

# 设置 C++ 编译器路径
# set(CMAKE_CXX_COMPILER "/path/to/mingw64/bin/g++.exe")
set(CMAKE_CXX_COMPILER "${CMAKE_SOURCE_DIR}/../mingw64/bin/g++.exe")

# 设置C++标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 包含头文件目录
include_directories(${CMAKE_SOURCE_DIR}/include)

# 链接库文件目录
link_directories(${CMAKE_SOURCE_DIR}/lib)

# 可执行文件
add_executable(program src/main1.cpp)

# 手动添加 OpenCV 库
if(CMAKE_BUILD_TYPE STREQUAL "Release")
    target_link_libraries(program opencv_world455)
else()
    target_link_libraries(program opencv_world455d)
endif()