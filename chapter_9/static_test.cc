
#include <iostream>
#include <utility>
#include <fmt/core.h>

using namespace std;

class A
{
public:
    void setData(int v)
    {
        m_data = v;
    };
    int getData()
    {
        return m_data;
    };

	//传递类引用， 则类静态方法则可以调用类的私有成员
	static int getData2(A & a)
	{
		//return this->m_data; // Error: 类静态方法本身没有this指针, 不能直接调用私有成员
		return a.m_data; 
	};

	//静态方法可以调用静态成员
	static int getData3()
	{
		return A::m_data3;
	};

private:
    int m_data;
	static int m_data3; //需要在全局进行初始化
};


//类的静态属性在类外的初始化格式
//private下的静态属性由于只有类可以访问，因此只能在全局区域进行初始化，不能在函数内初始化
//public下的静态属性可以被外部代码访问，所以不仅可以在全局区域初始化，也可以在函数内初始化。
//类的静态成员时属于类的，因此所有对象共享同一个静态成员的内存区域，因此某个对象修改了一次静态属性，将会影响所有对象。
int A::m_data3 = 0;

int main(int argc, char **argv)
{
    string s { fmt::format("my {} is {}", "age", 24) };
    fmt::print("s: {}\n", s);

    A a {};
    a.setData(10);

	fmt::print("m_data:{}", a.getData());

	fmt::print("m_data:{}", a.getData2(a));

	fmt::print("m_data:{}", A::getData3());

    return 0;
}

