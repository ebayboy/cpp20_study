
#include <iostream>
#include <utility>
#include <fmt/core.h>

using namespace std;

//函数重载不能只是返回值不同
void test()
{
    fmt::print("test voidt!\n");
}

int test(int a)
{
    fmt::print("test int!\n");
    return 0;
}

int main(int argc, char **argv)
{
    int a = test(10);

    test();

    return 0;
}

