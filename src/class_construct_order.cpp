
#include <iostream>
#include <utility>
#include <fmt/core.h>

using namespace std;

//C++ 派生类调用父类构造函数、变量调用顺序

// 1. 调用基类构造函数Base
// 2. 类的非静态成员创建 m_something
// 3. 执行类的构造函数Drived

class Something
{
public:
	Something () { cout << "Something construct...\n"; }
	virtual ~Something () {};

private:
	/* data */
};

class Base {
	public:
		Base() { cout << "Base construct ...\n";};
		virtual ~Base() {};
	private:
};

class Drived : public Base {
	public:
		Drived() { cout << "Drived construct ...\n";};
		virtual ~Drived() {};
	private:
		Something m_something;
};


int main(int argc, char **argv)
{
	Drived d;
	return 0;
}

