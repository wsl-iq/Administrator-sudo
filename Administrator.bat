@echo off
:: requires Administrator
net session >nul 2>&1
if %errorlevel% neq 0 (
    echo Program requires Administrator privileges Restarting...
    powershell -Command "Start-Process '%~f0' -Verb runAs -Wait"
    exit /b
)
:: bat
cd /d %~dp0
:: Run Program main
echo Welcome, I'm Mohammed Al-Baqer
if %errorlevel% neq 0 (
    echo Failed to execute the program.
    pause
)
pause