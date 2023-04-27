
#include <fmt/core.h>

#include <iostream>
#include <utility>

using namespace std;

class Base {
public:
    Base() { fmt::println("Base!"); };
    void show() { cout << "Base show()!" << endl; };
    virtual ~Base() = default;
};

class Drived : public Base {
public:
    Drived() { fmt::println("Drived!"); };
    void show() { cout << "Drived show()!" << endl; };
    virtual ~Drived() = default;
};

int main(int argc, char **argv) {
    // 1. int -> double
    int i{3};
    int j{4};
    double res = {static_cast<double>(i) / j};
    fmt::println("res:{}", res);

    // 2. 指针转换； 派生类对象 -> 基类
    Base *b;
    Drived *d{new Drived()};
    b = d;  // 向上转换不需要强制

    Base *b1{new Base()};
    Drived *d1;
    d1 = static_cast<Drived *>(b1);  // 向下转换需要使用强制转换
	d1->show();

	// 3. 引用转换
	Base b2; //向下转换， 需要强制转换
	Drived &d2 { static_cast<Drived &>(b2) };
	d2.show();
	
    return 0;
}

