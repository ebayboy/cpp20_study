
#include <iostream>
#include <utility>
#include <fmt/core.h>

using namespace std;

int main(int argc, char **argv)
{
	int a{3}, b{4}, c{};

	fmt::print("before exchange a:{} b:{} c:{}\n", a, b, c);

	c = exchange(a,b);

	fmt::print("after exchange a:{} b:{} c:{}\n", a, b, c);

	return 0;
}

