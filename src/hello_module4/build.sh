#!/bin/bash -x

# 编译系统header
g++ -fmodules-ts -std=c++20 -xc++-system-header iostream

# 编译接口声明文件
g++ -fmodules-ts -std=c++20 -xc++ -c foo.cppm -o foo.o
# 编译接口实现文件
g++ -fmodules-ts -std=c++20 -xc++ -c foo_impl.cppm -o foo_impl.o

# 编译测试文件 
g++ -fmodules-ts -std=c++20 -xc++ -c main.cpp -o main.o

# 连接文件
g++ foo.o foo_impl.o main.o

exit 0

