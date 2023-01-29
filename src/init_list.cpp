
#include <iostream>
#include <fmt/core.h>
#include <initializer_list>
#include <vector>

using namespace std;

int makeSum(initializer_list<int> values)
{
	int total {};
	for (int value : values) {
		total += value;
	}

	return total;
}

int makeSum2(vector<int> values)
{
	int total {};
	for (auto value : values) {
		total += value;
	}

	return total;
}


int main(int argc, char **argv)
{
	string s { fmt::format("my {} is {}", "age", 24) };
	fmt::print("s: {}\n", s);

	fmt::print("sum:{}\n", makeSum({1, 2, 3}));

	fmt::print("sum2:{}\n", makeSum2({1,2,3}));

	return 0;
}

