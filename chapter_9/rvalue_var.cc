
#include <iostream>
#include <utility>
#include <fmt/core.h>

using namespace std;


//右值引用变量

class A
{
	public:
		A() { cout << "construct..." << m_name << endl; };
		~A() { cout << "destruct..." << m_name << endl; };
		void setName(string name) 
		{
			m_name = name;
		};
	
	private:
		string m_name;
};
int main(int argc, char **argv)
{
	int && i {10};
	int a {10}, b{20};
	int && c { a + b };

	fmt::print("i:{} c:{}\n", i, c);

	//改变右值引用,  将3的右值给c
	c = 3;
	fmt::print("i:{} c:{}\n", i, c);

	cout <<"r1=========\n";
	A r1 = A();  //错误，无名临时变量 A() 是右值，因此不能初始化左值引用 r1
	r1.setName("r1");

	cout <<"r2=========\n";
	//没有进行复制，直接将r1右值拿过来, 同时r1也不要再使用了，所有没有r1不再调用析构函数
	A && r2 = std::move(r1); 
	r2.setName("r2"); 

	//改变右值引用, 改变右值引用后， 之前的右值r1会调用析构函数释放掉
	cout << "change r2 right value ref..." << endl;	
	r2 = A();
	r2.setName("r2-2"); 

	cout <<"r3=========\n";
	A r3 = r1; //相当于复制了一份r1
	r3.setName("r3");

	cout <<"done =========\n";

	return 0;
}

