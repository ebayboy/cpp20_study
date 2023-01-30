
#include <iostream>
#include <utility>

using namespace std;

void test_mem()
{
	int *p = nullptr;
	p = new int;
	*p = 10;
}

int main(int argc, char **argv)
{
	test_mem();

	return 0;
}

