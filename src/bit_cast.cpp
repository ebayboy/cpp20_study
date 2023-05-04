
#include <iostream>
#include <utility>
#include <fmt/core.h>
#include <bit>

using namespace std;

int main(int argc, char **argv)
{
	float a { 1.23f };

	fmt::println("a:{} bit_cast<float>:{} static_cast<int>:{} bit_cast<int>:{}", a, bit_cast<float>(a), static_cast<unsigned int>(a), bit_cast<int>(a));

	return 0;
}

