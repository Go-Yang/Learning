@echo off

REM 获取当前目录
set "current_dir=%cd%"

REM 设置 CMake 和 MinGW 的路径变量
set "CMAKE_PATH=%current_dir%\\..\\..\\buildTools\\cmake\\bin"
set "MINGW_PATH=%current_dir%\\..\\..\\buildTools\\mingw64\\bin"

REM 添加 MinGW 和 CMake 的路径到 PATH
set "PATH=%MINGW_PATH%;%CMAKE_PATH%;%PATH%"

REM 设置构建类型（可以通过参数传入，例如 Debug 或 Release）
set "build_type=%1"

REM 尝试删除 build 目录
set "delete_attempts=0"
:retry_delete
if exist build (
    echo Deleting existing build directory...
    rmdir /s /q build
    if exist build (
        echo Failed to delete build directory after 3 attempts. Ensure no other programs are using it.
        echo Please delete the build directory manually and try again.
        exit /b 1
    )
)

REM 创建并进入 build 目录
echo Creating build directory...
mkdir build
if errorlevel 1 (
    echo Failed to create build directory.
    exit /b 1
)
cd build

REM 生成构建系统文件
echo Configuring project...
"%CMAKE_PATH%\cmake.exe" -G "MinGW Makefiles" -DCMAKE_BUILD_TYPE=%build_type% -DCMAKE_MAKE_PROGRAM="%MINGW_PATH%\mingw32-make.exe" -DCMAKE_C_COMPILER="%MINGW_PATH%\gcc.exe" -DCMAKE_CXX_COMPILER="%MINGW_PATH%\g++.exe" ..
@REM "%CMAKE_PATH%\cmake.exe" -G "MinGW Makefiles" ^
@REM     -DCMAKE_BUILD_TYPE=%build_type% ^
@REM     -DCMAKE_MAKE_PROGRAM="%MINGW_PATH%\mingw32-make.exe" ^
@REM     -DCMAKE_C_COMPILER="%MINGW_PATH%\x86_64-w64-mingw32-gcc.exe" ^
@REM     -DCMAKE_CXX_COMPILER="%MINGW_PATH%\x86_64-w64-mingw32-g++.exe" ^
@REM     ..

if errorlevel 1 (
    echo CMake configuration failed.
    exit /b 1
)

REM 构建程序
echo Building project...
%MINGW_PATH%\mingw32-make.exe
if errorlevel 1 (
    echo Build failed.
    exit /b 1
)

chcp 65001

REM 运行程序
if exist .\program.exe (
    echo Running project...
    .\program.exe
) else (
    echo Executable not found, skipping run step.
)
