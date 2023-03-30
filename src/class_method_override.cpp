
#include <iostream>
#include <utility>
#include <fmt/core.h>

using namespace std;

class Demo {
	public:
		method1() {}
	private:
		int m_data;
};

int main(int argc, char **argv)
{
	string s { fmt::format("my {} is {}", "age", 24) };
	fmt::print("s: {}\n", s);

	return 0;
}

