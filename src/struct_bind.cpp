
#include <iostream>
#include <fmt/core.h>
#include <array>
#include <utility> //pair
#include <optional>

using namespace std;

optional<int> getData(bool g)
{
	if (g) {
		return 42;
	}

	return nullopt;
}

int main(int argc, char **argv)
{
	string s { fmt::format("my {} is {}", "age", 24) };
	fmt::print("s: {}\n", s);

	array values {1,2,3};
	auto [x,y,z] { values };

	fmt::print("x:{} y:{} z:{}\n", x, y, z);
	pair<int, double> mypair { 1, 3.14};

	auto [ m, n ] { mypair };
	fmt::print("m:{} n:{}\n", m, n);

	optional<int> data1 { getData(true) };
	optional<int> data2 { getData(false) };

	fmt::print("data1:{}\n", data1.value_or(0));

	fmt::print("data2:{}\n", data2.value_or(0));
	

	return 0;
}

