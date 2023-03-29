
#include <fmt/core.h>

#include <iostream>
#include <utility>

using namespace std;

class Base {
public:
    void method1() { fmt::println("m1"); };

protected:
    void method2() { fmt::println("m2"); };

private:
    int m_data;
};

// 不允许继承final
class Base2 final {
public:
    void method1() { fmt::println("m1"); };

protected:
    void method2() { fmt::println("m2"); };

private:
    int m_data;
};

// 公有继承
class Drived : public Base {
public:
    void method3() { fmt::println("m3"); };
};

// 私有继承， 默认继承方式, 访问基类的public, protected
class Drived2 : private Base {
public:
    void method3() {
	fmt::println("Drived2 m3:");
	method1();  // 可以在类内部访问基类public/protected成员
	method2();
    };
};

// Error: Base2 为final类， 不允许被继承 
// class Drived3 : public Base2 { };

int main(int argc, char **argv) {
    Drived d;
    d.method3();
    d.method1();  // public继承，可以在外部访问基类成员

    Drived2 d2;
    d2.method3();

    // d2.method1(); //Error: 不能在外部访问基类任何成员

    return 0;
}

