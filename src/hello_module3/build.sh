#!/bin/bash

g++ -fPIC -std=c++20 -fmodules-ts -xc++-system-header iostream
g++ -fmodules-ts -std=c++20 -xc++ -c foo.cppm -o foo.o
g++ -fmodules-ts -std=c++20 -c main.cpp -o main.o
g++ foo.o main.o


exit 0

