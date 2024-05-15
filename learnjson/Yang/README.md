
你确实很聪明！能够将项目设置成可移植的形式，并能在没有特定开发环境的计算机上运行，确实是一项重要的技能。这样做不仅增加了项目的灵活性，还能确保其他开发人员和用户能够更方便地使用你的项目。

以下是关于项目设置的几个要点，确保你的项目在任何环境下都能顺利运行：

自包含：所有必需的工具和库都包含在项目目录中，不需要依赖系统安装的工具。
自动化脚本：通过批处理脚本（如 make.bat），自动化编译和运行过程，减少人为错误。
相对路径：使用相对路径来确保脚本和配置文件能正确定位到项目中的工具和库。
简单易用：任何人都可以通过运行一个简单的脚本来编译和运行项目，而不需要了解具体的编译步骤或安装额外的软件。
如果还有其他问题或者需要进一步的帮助，请随时告诉我！以下是最终项目结构和 make.bat 的内容，供参考：

项目结构

```c++
Yang/
├── program/
│   ├── include/
│   │   ├── opencv2/
│   │   │   ├── core.hpp
│   │   │   ├── imgcodecs.hpp
│   │   │   ├── imgproc.hpp
│   │   │   ├── highgui.hpp
│   │   │   └── ...  // 其他OpenCV头文件
│   │   └── json/
│   │       └── json.hpp  // JSON for Modern C++头文件
│   ├── lib/
│   │   ├── opencv_world455.lib
│   │   └── opencv_world455d.lib
│   ├── src/
│   │   └── main.cpp
│   ├── CMakeLists.txt
│   ├── README.md
│   └── make.bat
├── mingw64/
│   └── bin/
│       └── g++.exe
└── cmake/
    └── bin/
        └── cmake.exe
```

make.bat 内容

```bash
@echo off

REM 获取当前目录
set "current_dir=%cd%"

REM 如果build目录存在则删除
if exist build (
    echo Deleting existing build directory...
    rmdir /s /q build
    if exist build (
        echo Failed to delete build directory. Ensure no other programs are using it.
        exit /b 1
    )
)

REM 创建并进入build目录
echo Creating build directory...
mkdir build
cd build

REM 生成构建系统文件
echo Configuring project...
"%current_dir%\..\cmake\bin\cmake.exe" -DCMAKE_BUILD_TYPE=%1 ..
if errorlevel 1 (
    echo CMake configuration failed.
    exit /b 1
)

REM 构建程序
echo Building project...
"%current_dir%\..\cmake\bin\cmake.exe" --build .
if errorlevel 1 (
    echo Build failed.
    exit /b 1
)

REM 运行程序
echo Running program...
if "%1" == "Debug" (
    .\Debug\program.exe
) else (
    .\Release\program.exe
)

```


运行这个脚本时，打开终端并进入 Yang/program 目录，然后执行：

```bash
.\make.bat Debug
```


或者：

```
.\make.bat Release
```


这样可以确保项目在不同环境下都能顺利编译和运行。祝你在项目开发中一切顺利！如果有其他问题，随时联系我。

```bash
#!/bin/bash

# 获取当前目录
current_dir=$(pwd)

# 如果build目录存在则删除
if [ -d "build" ]; then
    echo "Deleting existing build directory..."
    rm -rf build
    if [ -d "build" ]; then
        echo "Failed to delete build directory. Ensure no other programs are using it."
        exit 1
    fi
fi

# 创建并进入build目录
echo "Creating build directory..."
mkdir build
cd build

# 生成构建系统文件
echo "Configuring project..."
"${current_dir}/../cmake/bin/cmake" -DCMAKE_BUILD_TYPE=$1 ..
if [ $? -ne 0 ]; then
    echo "CMake configuration failed."
    exit 1
fi

# 构建程序
echo "Building project..."
"${current_dir}/../cmake/bin/cmake" --build .
if [ $? -ne 0 ]; then
    echo "Build failed."
    exit 1
fi

# 运行程序
echo "Running program..."
if [ "$1" == "Debug" ]; then
    ./Debug/program
else
    ./Release/program
fi

```

```bash
chmod +x make.sh
./make.sh Debug
./make.sh Release
```

