
#include <fmt/core.h>

#include <iostream>
#include <string>
#include <utility>

// 1. 使用名称空间
using namespace std;

// 2. 类型别名， 类似 typedef
typedef std::string TString;
using UString = std::string;

// 函数指针
// typedef void(tFunc *)(void);
using callback_cpp = void (*)(void);

// 3.私有继承基类， 外部使用基类方法
class Base {
public:
    Base() = default;
    virtual ~Base() = default;
    void dist1() { cout << "dist1\n"; };
    void dist2() { cout << "dist2\n"; };

private:
    int m_data;
};

class Drived : private Base {
public:
    Drived() = default;
    virtual ~Drived() = default;

    using Base::dist1;	// 私有继承， 通过using 使用基类的方法
    void showDist2() { this->dist2(); };

private:
};

int main(int argc, char **argv) {
    TString ts{"TString"};
    UString us{"UString"};

    fmt::println("ts:{}", ts);
    fmt::println("us:{}", us);

    Drived d;
    d.showDist2();
    d.dist1();

    return 0;
}

