@echo off

echo.slice 1.2.0 release 1
echo.slice test script - Microsoft Windows OS environment
echo.================================================================================

if not exist "destination" mkdir destination

echo.
echo.test case 01: slice source file into n=32 chunks
echo.--------------------------------------------------------------------------------
echo.

slice.exe -i source\test.dat -o destination -c 32 -v

echo.
dir destination
del destination\* /q
echo.

echo.test case 02: slice source file into n=32 chunks showing file names
echo.--------------------------------------------------------------------------------
echo

slice.exe -i source\test.dat -o destination -c 32 -s -v

echo.
dir destination
del destination\* /q
echo.

echo.test case 03: slice source file into n=8192 chunks showing file names
echo.--------------------------------------------------------------------------------
echo.

slice.exe -i source\test.dat -o destination -c 8192 -s -v

echo
dir destination
del destination\* /q
echo

echo.test case 04: slice source file into 2 parts
echo.--------------------------------------------------------------------------------
echo.

slice.exe -i source\test.dat -o destination -p 2 -v

echo.
dir destination
del destination\* /q
echo.

echo.test case 05: slice source file into 2 parts showing file names
echo.--------------------------------------------------------------------------------
echo.

slice.exe -i source\test.dat -o destination -p 2 -s -v

echo.
dir destination
rem del destination\* /q
echo.

echo.test case 06: slice source file into 8 parts showing file names
echo.--------------------------------------------------------------------------------
echo.

slice.exe -i source\test.dat -o destination -p 8 -s -v

echo.
dir destination
del destination\* /q
echo.
