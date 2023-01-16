
#define FMT_HEADER_ONLY

#include <fmt/core.h>

// g++ -std=c++20 -lfmt -I /usr/local/fmt/include/ -L /usr/local/fmt/lib/ fmt_test.cpp  -o fmt_test

int main() {
	std::string s = fmt::format("The answer is {}.", 42);
	fmt::print("s:{}\n", s);
	fmt::print("Hello, world!\n");
}
