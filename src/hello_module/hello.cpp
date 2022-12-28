
module;

#include <iostream>
#include <string_view>
#include <concepts>

export module smd.hello;

export namespace hello
{

template<std::integral T> // 引用头文件中的符号
T square(T x)
{
    return x * x;
}

void hello(std::string_view name)
{
    std::cout << "hello, " << name << "!" << std::endl;
}

}
