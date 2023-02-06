
#include <iostream>
#include <utility>
#include <fmt/core.h>

using namespace std;

//委托构造函数: 构造函数调用另一个构造函数， 只能在初始化器中完成
class MyClass 
{
	public:
		MyClass(char c) : MyClass{ 1.2 } 
		{
			cout << "MyClassu char construct...\n";
		};
		MyClass(double d) 
		{
			cout << "MyClassu double construct...\n";
		};
};


int main(int argc, char **argv)
{
	cout <<"c1:\n";
	MyClass c1 { 'c' };

	cout << "c2:\n";
	MyClass c2 { 2.0 };

	return 0;
}

