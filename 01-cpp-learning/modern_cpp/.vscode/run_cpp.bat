@echo off
chcp 65001 >nul
set FILE=%1
set DIR=%~dp1
set NAME=%~n1

echo === 编译 %NAME% ===
"C:\Program Files\LLVM\bin\clang.exe" -std=c++17 -g "%FILE%" -o "%DIR%%NAME%.exe"
if %ERRORLEVEL% NEQ 0 (
    echo 编译失败！
    exit /b 1
)

echo === 运行 %NAME% ===
"%DIR%%NAME%.exe"
echo.
pause
