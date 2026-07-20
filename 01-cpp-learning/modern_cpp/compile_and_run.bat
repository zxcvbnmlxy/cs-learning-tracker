@echo off
chcp 65001 >nul
"C:\Program Files\LLVM\bin\clang++.exe" -std=c++17 -g unordered_bucket.cpp -o unordered_bucket.exe
if %ERRORLEVEL% EQU 0 (
    unordered_bucket.exe
)
pause
