@echo off
set "PATH=%USERPROFILE%\tools\sqlite;%PATH%"
cd /d "%~dp0"
node "%APPDATA%\npm\node_modules\node-red\red.js"
pause
