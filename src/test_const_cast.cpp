
#include <iostream>
#include <fmt/core.h>
#include <utility>

using namespace std;

void f(const char * str)
{
	char * a = const_cast<char *>(str);
	cout << "a:" << a << endl;
}

int main(int argc, char **argv)
{
	char *a1 = (char *)"hello";
	f (a1);

	string str {"c++"};
	const string & constStr { as_const(str) };
	cout << "constStr:" << constStr << endl;

	return 0;
}

