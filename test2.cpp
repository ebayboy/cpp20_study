
#include <iostream>
#include <fmt/core.h>

using namespace std;

int main(int argc, char **argv)
{
	string s { fmt::format("my {} is {}", "age", 24) };
	fmt::print("s: {}\n", s);

	return 0;
}

