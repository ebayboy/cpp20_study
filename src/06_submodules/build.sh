#!/bin/bash

g++ -fmodules-ts -std=c++20 -x c++-system-header iostream
g++ -fmodules-ts -std=c++20 -x c++ -c datamodel.address.cppm -o datamodel.address.o
g++ -fmodules-ts -std=c++20 -x c++ -c datamodel.address.cpp -o datamodel.address_impl.o
g++ -fmodules-ts -std=c++20 -x c++ -c test.cpp -o test.o
g++ datamodel.address.o datamodel.address_impl.o test.o

exit 0

