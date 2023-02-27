
#include <iostream>
#include <utility>
#include <fmt/core.h>

using namespace std;

class A
{
public:

	//1. const 方法不允许修改数据成员
    int  getData() const  
    {
		//m_data = 10; //如果方法指定const，如果修改m_data, 编译器会报错
        return m_data;
    };

	//2. const方法只允许调用const方法
	int getData2() const 
	{
		count++; //OK: const方法可以改变mutable的值
		
		printData();
		//m_count++; //Error: const方法 改变了数据成员的值
		
		return m_data;
	};

	void printData() const 
	{
		fmt::print("printData:{} count:{}\n", m_data, count);
	};

private :
    int m_data;
	int m_count {0};

	// 3.mutable - 可变数据成员，const方法可改变这个变量的值
	mutable int count {0}; 
};

int main(int argc, char **argv)
{
    A a {};

    fmt::print("d1:{}\n", a.getData());

    fmt::print("d2:{}\n", a.getData2());

    return 0;
}

