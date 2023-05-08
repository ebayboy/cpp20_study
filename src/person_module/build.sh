#!/bin/bash


# 1. build system module used
g++ -fPIC -std=c++20 -fmodules-ts -xc++-system-header iostream 
g++ -fPIC -std=c++20 -fmodules-ts -xc++-system-header string

# 2. build module:  person.o
g++ -fPIC -fmodules-ts -std=c++20 -o person.o -c person.cpp

# 3. build main module test_person.o
g++ -fPIC -fmodules-ts -std=c++20 -o test_person.o -c test_person.cpp

# 4. build main
g++ -fPIC -fmodules-ts -std=c++20 -o test_person test_person.o person.o 

exit 0

