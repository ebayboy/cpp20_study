
#include <iostream>
#include <utility>
#include <fmt/core.h>
#include <vector>

#include <stdlib.h>

using namespace std;

void test_mem()
{
	int *p = nullptr;
	p = new int;
	*p = 10;
	delete p;
	p = nullptr;
}

int main(int argc, char **argv)
{
	vector<int> v { 11, 22, 33};

	for(auto & i:v) 
	{
		cout << i << endl;
	}

	fmt::print("v.at(0):{}\n", v.at(1));

	//test_mem();
	int *ptr { nullptr };
	 ptr = new int;
	*ptr = 10;

	delete ptr;
	ptr =  nullptr; //ptr设置为nullptr后进行delete不会做任何事
	delete ptr; //不会crash

	return 0;
}

