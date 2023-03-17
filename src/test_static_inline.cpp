
// 类的静态成员的定义及初始化
#include <iostream>
#include <utility>
#include <fmt/core.h>

using namespace std;


class Demo
{
public:
	Demo (){};
	~Demo (){};
	
	//static int counter; //方式一: 类内声明 类外初始化(定义)
	static inline int counter; //方式二: C++17, 在类内部初始化 

private:
	int m_data;
};

//int Demo::counter {0}; //方式一：在类的外部初始化，分配内存

int main(int argc, char **argv)
{
#if 0
	//实例化调用
	Demo d{};
	cout << "d.counter:" << d.counter << endl;
#else
	//不实例话调用	
	cout << "d.counter:" << Demo::counter << endl;
#endif
	
	return 0;
}


