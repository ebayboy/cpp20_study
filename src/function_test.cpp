
#include <iostream>
#include <utility>
#include <fmt/core.h>

using namespace std;

void func(void)
{
	cout << "func\n";
}

int main(int argc, char **argv)
{
	using func_ptr = void (*)(void);
	func_ptr = func;

	return 0;
}

