
#include <iostream>
#include <utility>
#include <fmt/core.h>

using namespace std;

class Demo
{
public:
	Demo (int arg1, int arg2, int arg3);
	void Show();
	~Demo ();
private:
	/* data */
	int m_arg1;
	int m_arg2;
	mutable int m_arg3;
};


#if 1
//构造函数参数使用默认值
Demo::Demo(int arg1 = 100, int arg2 = 200, int arg3 = 300)
{
	fmt::print("Constructor...\n");
	m_arg1 = arg1;
	m_arg2 = arg2;
	m_arg3 = arg3;
}
#else
//构造函数参数使用初始化器
Demo::Demo(int arg1, int arg2, int arg3) : m_arg1(arg1), m_arg2(arg2), m_arg3(arg3)
{
}
#endif

Demo::~Demo()
{
	fmt::print("Destructor...\n");
}

void Demo::Show()
{
	fmt::print("arg1:{}  arg2:{} arg3:{}\n", m_arg1, m_arg2, m_arg3);
}

int main(int argc, char **argv)
{
#if 1
	//参数使用默认值
	// 1. 构造函数如果没有默认值， 必须传递3个参数
	Demo d{ 1, 2, 3 };
	d.Show();

	// 2. 构造函数：参数有默认值， 可以传递任意个参数
	Demo d2{ 1, 2 };
	d2.Show();

	Demo d3{};
	d3.Show();
#else
	//使用初始化器
	Demo d{ 1, 2, 3 }; //ok
	d.Show();
#endif


	return 0;
}

