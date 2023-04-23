
#include <iostream>
#include <utility>
#include <fmt/core.h>

using namespace std;

// 参数默认值不会被重写, 参数默认值是在编译期决定的

class Base {
	public:
		void virtual go(int a = 2) { cout << "Base go:" << a << endl; };
};

class Drived : public Base {
	public:
		//重写基类具有默认参数的方法， 默认参数值应保持相同  a = 2
		void go(int a = 7) override { cout << "Drived go:" << a << endl; };
};

int main(int argc, char **argv)
{
	Base b1;
	b1.go();

	Drived d;
	d.go();

	Base &b {d}; //代码段指向的是Drived的代码段
	b.go(); //默认参数值不会被重写

	return 0;
}

