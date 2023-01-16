
#include <iostream>
#include <format>

//暂时g++11编译找不到format
int main()
{
    std::cout << std::format("Hello {}!\n", "world");
}

