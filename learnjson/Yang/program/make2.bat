@echo off

REM 获取当前目录
set "current_dir=%cd%"

REM 检查输入参数
if "%1"=="" (
    echo Usage: make.bat [Debug|Release]
    exit /b 1
)

set "build_type=%1"

REM 尝试删除 build 目录
set "delete_attempts=0"
:retry_delete
if exist build (
    echo Deleting existing build directory...
    rmdir /s /q build
    if exist build (
        set /a delete_attempts+=1
        if %delete_attempts% geq 3 (
            echo Failed to delete build directory after 3 attempts. Ensure no other programs are using it.
            echo Please delete the build directory manually and try again.
            exit /b 1
        )
        echo Failed to delete build directory. Retrying in 3 seconds...
        timeout /t 3 /nobreak > nul
        goto retry_delete
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
"%current_dir%\..\cmake\bin\cmake.exe" -DCMAKE_BUILD_TYPE=%build_type% ..
if errorlevel 1 (
    echo CMake configuration failed.
    exit /b 1
)

REM 构建程序
echo Building project...
"%current_dir%\..\cmake\bin\cmake.exe" --build . --config %build_type%
if errorlevel 1 (
    echo Build failed.
    exit /b 1
)

REM 运行程序
set "exe_path=%current_dir%\build\%build_type%\program.exe"
if exist "%exe_path%" (
    echo Running program...
    "%exe_path%"
) else (
    echo Executable not found: %exe_path%
    exit /b 1
)
