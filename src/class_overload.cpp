
#include <iostream>
#include <utility>
#include <fmt/core.h>

using namespace std;


class Base {
	public:
		void virtual func() { cout << "Base func\n"; };
		void virtual func(int a) { cout << "Base func:" << a << endl; };
};

class Drived : public Base {
	public:
		using Base::func; //使用基类func
		void func() override { cout << "Drived func\n"; };
};

int main(int argc, char **argv)
{
	Drived d;
	d.func(); // 1. call overload
	d.func(1);// 2. call using Base::func;

	Base & b{d};
	b.func(1); // 3. 转换成基类

	return 0;
}

