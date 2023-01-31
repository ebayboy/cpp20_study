
#include <iostream>
#include <utility>
#include <fmt/core.h>

#include <memory>

using namespace std;
int idx {0};

void foo(std::shared_ptr<int> p)
{
	(*p)++;
	fmt::print("{} use_count:{}\n", __LINE__ , p.use_count());
}

int main(int argc, char **argv)
{
	auto p { make_shared<int>(10) }; //int类型, 初始值10
	foo(p);
	cout << *p << endl;
	fmt::print("{} use_count:{}\n", __LINE__ , p.use_count());

	auto p2 { p };
	auto p3 { p };
	fmt::print("{} use_count:{}\n", __LINE__ , p.use_count());
	
	return 0;
}

