
#include <iostream>
#include <fmt/core.h>

using namespace std;

int main(int argc, char **argv)
{
	//1. 强排序 strong_ordering, 整数
	int i {11};
	strong_ordering result { i <=> 0};
	fmt::print("result: {}\n", result);

	//2. 偏排序 partial_ordering, 

	//3. weak_ordering
	

	return 0;
}

