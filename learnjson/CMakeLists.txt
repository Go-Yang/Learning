cmake_minimum_required(VERSION 3.7)
project(jsonpractice)

# 设置C++标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 添加头文件目录
include_directories(G:\\git_repo\\Learning\\learnjson\\include)
include_directories(G:\\git_repo\\Learning\\learnjson\\include\\json)
# 添加源文件
add_executable(jsonpractice src/main.cpp)
