
#include <iostream>
#include <utility>
#include <fmt/core.h>

using namespace std;

class Base {
	public:
		void virtual go(int a = 2) { cout << "Base go:" << a << endl; };
};

class Drived : public Base {
	public:
		void go(int a = 7) override { cout << "Drived go:" << a << endl; };
};

int main(int argc, char **argv)
{
	Base b1;
	b1.go();

	Drived d;
	d.go();

	Base &b {d}; //代码段指向的是Drived的代码段
	b.go();

	return 0;
}

