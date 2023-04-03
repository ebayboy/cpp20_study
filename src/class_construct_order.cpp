
#include <iostream>
#include <utility>
#include <fmt/core.h>

using namespace std;

//C++ 派生类调用父类构造函数、变量调用顺序

// 派生类的创建顺序
// 1. 调用基类构造函数Base
// 2. 类的非静态成员创建 m_something
// 3. 执行类的构造函数Drived

// 派生类的销毁顺序与构造顺序相反

class Something
{
public:
	Something () { cout << "Something construct...\n"; }
	virtual ~Something () { cout << "Something destruct!\n"; };

private:
	/* data */
};

class Base {
	public:
		Base() { cout << "Base construct ...\n";};
		virtual ~Base() { cout << "Base destruct\n"; };
	private:
};

class Drived : public Base {
	public:
		Drived() { cout << "Drived construct ...\n";};
		virtual ~Drived() { cout << "Drived destruct\n"; };
	private:
		Something m_something;
};


int main(int argc, char **argv)
{
	Drived d;
	return 0;
}

