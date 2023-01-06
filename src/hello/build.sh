#!/bin/bash

# ***************************************************************************
# * 
# * @file:build.sh 
# * @author:ebayboy@163.com 
# * @date:2023-01-06 17:02 
# * @version 1.0  
# * @description: Shell script 
# * @Copyright (c)  all right reserved 
#* 
#**************************************************************************/ 

# 1. 先将系统头文件编译成module
g++ -std=c++20 -fmodules-ts -xc++-system-header iostream

# 2. 编译hello
g++ -std=c++20 -fmodules-ts -o hello hello.cpp 

exit 0

