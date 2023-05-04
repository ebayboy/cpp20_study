
#include <iostream>
#include <utility>
#include <fmt/core.h>
#include <bit>

using namespace std;

int main(int argc, char **argv)
{
	float a { 1.23f };

	unsigned int b = bit_cast<unsigned int>(a);
	unsigned int s = static_cast<unsigned int>(a);

	float new_a = bit_cast<float>(b); //bit_cast按位复制， 可以转回去

	fmt::println("a:{} static_cast<int>:{} bit_cast<int>:{} new_a:{}", a, s, b, new_a);

	return 0;
}

