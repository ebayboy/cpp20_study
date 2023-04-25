
#include <iostream>
#include <utility>
#include <fmt/core.h>

#include <typeinfo>

using namespace std;

// RTTI: 运行时特性
//
// 特性1：dynamic_cast()
// 特性2: typeid()

int main(int argc, char **argv)
{
	int a;

	if (typeid(a) == typeid(int)) {
		fmt::println("int");
	} else {
		fmt::println("not int");
	}

	return 0;
}

