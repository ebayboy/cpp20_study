
#include <fmt/core.h>

#include <iostream>
#include <utility>

using namespace std;

// 三向比较运算符以及在类操作符重载中中的应用

class Demo {
public:
    Demo(int v) : m_value(v){};
    ~Demo(){};
    int getValue() const { return m_value; };
    auto operator==(Demo const &r) { return (r.getValue() == getValue()); };
    auto operator<=>(Demo const &r) { return (getValue() > r.getValue()); };

private:
    /* data */
    int m_value;
};

int main(int argc, char **argv) {
    Demo d1{1};
    Demo d2{2};

    auto res = (d1 == d2);
    fmt::println("res:{}", res);

	auto res1 = (d1 > d2);
    fmt::println("res1:{}", res1);

    return 0;
}

