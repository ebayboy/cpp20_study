
#include <iostream>
#include <utility>
#include <fmt/core.h>
#include <memory>

using namespace std;

class Simple
{
public:
	Simple (int value) : m_data { value } 
	{ 
		fmt::print("construct...{}\n", m_data);
	};
	~Simple () 
	{
		fmt::print("destruct! {}\n", m_data);
	};
	int m_data;
};

void useSimple(weak_ptr<Simple> & s)
{
	auto r { s.lock() };
	if (r) {
		fmt::print("alive!\n");
	} else {
		fmt::print("freed!\n");
	}

}

int main(int argc, char **argv)
{
	auto s1 { make_shared<Simple>(10) };

	useSimple(s1);

	return 0;
}

