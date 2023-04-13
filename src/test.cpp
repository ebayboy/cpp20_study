
#include <iostream>
#include <utility>
#include <fmt/core.h>
#include <vector>
#include <string>

// 成员函数声明时可以没有形参， 但定义时需要有形参a

using namespace std;

int main(int argc, char **argv)
{
	string s1 {"1.11"};
	string s2 {"2.22"};

	auto s3 = s1 + s2;

	cout << s3 << endl;

	return 0;
}

