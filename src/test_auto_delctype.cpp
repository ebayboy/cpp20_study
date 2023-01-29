
#include <iostream>
#include <fmt/core.h>
#include <initializer_list>

using namespace std;

const string message { "Test" };
const string & foo() 
{ 
	return message; 
}

int main(int argc, char **argv)
{
	int i {123};
	auto p { &i }; //p的类型为int *
	fmt::print("p:{}\n", *p);

	auto *p2{ &i }; //建议使用auto *， 能更清楚的表达是指针类型
	fmt::print("p2:{}\n", *p2);

	//拷贝列表初始化 copy-list-initialization
	auto a = {11};
	for (auto it=a.begin();it!=a.end();it++) {
		cout << *it << endl;
	}

	auto list = { 11, 22 };
    std::cout << typeid(decltype(list)).name() << std::endl;   //类型: St16initializer_listIiE
	for (auto it=list.begin();it!=list.end();it++) {
		cout << *it << endl;
	}
	
	//直接列表初始化 direct-list-initialization
	auto a1 {33}; //int类型
    std::cout << "a1 type:" << typeid(decltype(a1)).name() << std::endl;   //type i

#if 0
	//error: direct-list-initialization of ‘auto’ requires exactly one element [-fpermissive]
	//note: for deduction to ‘std::initializer_list’, use copy-list-initialization (i.e. add ‘=’ before the ‘{’)
	auto list1 {44, 55}; //Error: too many elements
	for (auto it=list1.begin();it!=list1.end();it++) {
		cout << *it << endl;
	}
#endif

	//decltype
	int x { 123 };
	decltype(x) y {456};
	fmt::print("x:{} y:{}\n", x, y);

	auto f1 { foo() };
	fmt::print("f1:{} message:{}\n", f1, message);
	f1 = "hello"; //f1的值被修过了，但message的值没变化， 说明去除了引用和const
	fmt::print("f1-2:{} message:{}\n", f1, message);

	decltype(foo()) f2 { foo() };
	fmt::print("f2:{} message:{}\n", f2, message);
	//f2 = "world"; //Error: error: invalid conversion from ‘const char*’ to ‘char’

	return 0;
}

