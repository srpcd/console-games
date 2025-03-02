@echo off
cls

echo Making...
echo.
make clean all

if errorlevel 1 (
	echo.
	echo An error occurred. Please try again later.
	pause
	@echo on
) else (
	@echo on
	start conhost ConsoleGames.exe
)