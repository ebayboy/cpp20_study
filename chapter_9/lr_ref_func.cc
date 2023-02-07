
#include <iostream>
#include <utility>
#include <fmt/core.h>
#include <string>

//右值引用函数

using namespace std;

#if 1
//left value
void handleMessage(string const &s)
{
	fmt::print("lvalue:{}\n", s);
}
#endif

//rvalue: 需要右值参数
void helper(string const && message)
{
	fmt::print("helper rvalue:{}\n", message);
}

#if 1
//right value
void handleMessage(string const && s)
{
	fmt::print("rvalue:{}\n", s);

	helper(std::move(s)); //参数s是有名称的、是左值， 需要转换成右值std::move
}
#endif


int main(int argc, char **argv)
{
	string a { "hello" };
	string b { " world" };

	handleMessage(a); //调用左值引用

	//优先选择右值引用， 如果没有右值引用会调用左值引用
	handleMessage(a + b); 

	//优先选择右值引用， 如果没有右值引用会调用左值引用
	handleMessage("hello, fanpf"); //

	//优先选择右值引用， 如果没有右值引用会调用左值引用
	//std::move将左值转换成右值
	handleMessage(std::move(b)); 

	return 0;
}

