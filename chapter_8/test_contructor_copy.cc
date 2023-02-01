
#include <iostream>
#include <memory>
#include <utility>

#include <fmt/core.h>

using namespace std;


class A {
	public:
		A() { cout << "construct...\n"; };

#if 1
		//调用显示拷贝构造函数， 只拷贝了m_age
		A(A const &a) 
		{ 
			m_age = a.m_age;
			cout << "copy construct...\n" << endl;
		};
#endif

		void setData(int data) { m_data = data; };
		int getData() { return m_data; };

		void setAge(int data) { m_age = data; };
		int getAge() { return m_age; };

	private:
		int m_data;
		int m_age;
};

//参数值传递： string 被复制
void printString(string s)
{
	fmt::print("s1:{}\n", s);
	cout << s << endl;
	s = "world";
	fmt::print("s2:{}\n", s);
}


int main(int argc, char **argv)
{
#if 0
	string s { R"("Hello")" };
	printString(s);
	fmt::print("s3:{}\n", s);
#endif
	A a;
	a.setAge(10);
	a.setData(20);

	A b { a };
	fmt::print("m_age:{} m_data:{}\n", b.getAge(), b.getData());

	return 0;
}

