可移植项目 (demo for windows)

项目目录结构
Portable/
├── cmake/                # 包含CMake二进制文件
│   └── bin/
│       └── cmake.exe     # CMake可执行文件
├── mingw64/              # 包含MinGW工具链
│   └── bin/
│       ├── gcc.exe       # GCC编译器
│       ├── g++.exe       # G++编译器
│       └── mingw32-make.exe # Make工具
└── program/
    ├── make.bat          # Windows 构建脚本
    ├── CMakeLists.txt    # CMake配置文件
    ├── src/              # 源代码目录
    │   ├── main.cpp      # 主源文件
    │   └── utils.cpp     # 其他源文件
    ├── include/          # 头文件目录
    │   └── myprogram/    # 项目头文件子目录
    │       └── utils.h   # 头文件
    └── build/            # 构建输出目录（由脚本创建）
