#!/bin/sh

echo slice 1.1.0 release 1
echo slice test script - open systems environments
echo ================================================================================

if [ -d destination ]; then
    rm -rf destination
fi

mkdir destination

echo
echo test case 01: slice source file into n=32 chunks
echo --------------------------------------------------------------------------------
echo

./slice -i source/test.dat -o destination -c 32 -v

echo
ls -ls destination
rm destination/*
echo

echo test case 02: slice source file into n=32 chunks showing file names
echo --------------------------------------------------------------------------------
echo

./slice -i source/test.dat -o destination -c 32 -s -v

echo
ls -ls destination
rm destination/*
echo

echo test case 03: slice source file into n=8192 chunks showing file names
echo --------------------------------------------------------------------------------
echo

./slice -i source/test.dat -o destination -c 8192 -s -v

echo
ls -ls destination
rm destination/*
echo

echo test case 04: slice source file into 2 parts
echo --------------------------------------------------------------------------------
echo

./slice -i source/test.dat -o destination -p 2 -v

echo
ls -ls destination
rm destination/*
echo

echo test case 05: slice source file into 2 parts showing file names
echo --------------------------------------------------------------------------------
echo

./slice -i source/test.dat -o destination -p 2 -s -v

echo
ls -ls destination
rm destination/*
echo

echo test case 06: slice source file into 8 parts showing file names
echo --------------------------------------------------------------------------------
echo

./slice -i source/test.dat -o destination -p 8 -s -v

echo
ls -ls destination
rm destination/*
echo
