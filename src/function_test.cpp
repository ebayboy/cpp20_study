
#include <iostream>
#include <utility>
#include <fmt/core.h>

using namespace std;

//1. 
void func(void)
{
	cout << "func\n";
}
using UFUNC = void (*)(void);

//2.
class Foo {
public:
	void operator()(void)
	{
		cout << "Foo.operator()\n";
	};
};

//3. 一个可被转换为函数指针的类对象
class Bar {
	public:
		//定义fr_t为函数指针
		using fr_t = void(*)(void);
		static void func(void) { };

		// 重新操作符()，返回函数指针
		operator fr_t(void) 
		{
			cout << "Bar.fr_t()\n";
			return func; //返回函数指针
		};
};

//4. 类的成员函数
class A {
	public:
		void mem_func(void)
		{
			cout << "A.mem_func\n";
		};
};

int main(int argc, char **argv)
{
	// 1. func函数指针
	UFUNC uf = func;
	uf();

	//2. 实现操作符()的类
	Foo foo;
	foo();

	//3. 一个可被转换为函数指针的类对象
	Bar b;
	b();

	//4. 类成员函数
	A a;
	a.mem_func();

	return 0;
}

