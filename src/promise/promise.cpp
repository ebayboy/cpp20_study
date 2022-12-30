/** @file  20190815future.cpp
*  @note
*  @brief
*  @author
*  @date   2019-8-15
*  @note
*  @history
*  @warning
*/
#include <iostream>
#include <functional>
#include <future>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <string>

void thread_set_promise(std::promise<int>& promiseObj)
{
    std::cout << "thread start...\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    promiseObj.set_value(35);
    std::cout << "thread Finished\n";
}

int main()
{
    std::promise<int> promiseObj;
    std::future<int> futureObj = promiseObj.get_future();

    std::thread t(&thread_set_promise, std::ref(promiseObj));
    std::cout << futureObj.get() << std::endl;
    t.join();

    std::cout << "t.join done!\n";

    return 0;
}
