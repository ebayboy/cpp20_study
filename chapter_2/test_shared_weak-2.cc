
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

void useSimple(weak_ptr<Simple>& weak_simple)
{
	auto s = weak_simple.lock(); //lock() 返回share_ptr类型
	if (s) {
		fmt::print("useSimple alive! m_data:{} use_count:{}\n", s->m_data, s.use_count());
	} else {
		fmt::print("useSimple freed!\n");
	}
}

int main(int argc, char **argv)
{
	auto share_simple { make_shared<Simple>(10) };
	//访问类成员用->, 访问shared_ptr成员函数用.
	fmt::print("share_simple: {} use_count:{}\n", share_simple->m_data, share_simple.use_count());

	weak_ptr<Simple> weak_simple { share_simple };
	useSimple(weak_simple);

	share_simple.reset();
	useSimple(weak_simple);

	return 0;
}

