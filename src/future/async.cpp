
#include <iostream>       // std::cout
#include <future>         // std::async, std::future
#include <chrono>         // std::chrono::milliseconds

//std::async就是异步编程的高级封装，封装了std::future的操作，基本上可以代替std::thread 的所有事情。
//素数: 除本身的绝对值外、不可能为大于1的整数除尽的数。
bool is_prime (int x)
{
    for (int i = 2; i < x; ++i)
        if (x % i == 0)
            return false;

    return true;
}

//异步计算444444443是否为素数
int main ()
{
    int num = 444444443;

    std::future<bool> fut = std::async (is_prime, num);
    std::chrono::milliseconds span(100);

    std::cout << "checking, please wait";

    //每100ms检查是否完成
    while (fut.wait_for(span) == std::future_status::timeout)
        std::cout << '.' << std::flush;

    //获取函数返回值
    bool x = fut.get();     // retrieve return value

    std::cout << "\n" << num << (x ? " is " : " is not ") << "prime\n";

    return 0;
}
