
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

//shared_ptr<T>作为函数参数时， 无论是值传递还是引用传递都增加引用计数， 两者效果一样。
//void useSimpleShared(shared_ptr<Simple>& s)
void useSimpleShared(shared_ptr<Simple> s)
{
	s->m_data++;
	fmt::print("useSimple alive! m_data:{} use_count:{}\n", s->m_data, s.use_count());
}


/*
construct...10
share_simple: 10 use_count:1
useSimple alive! m_data:10 use_count:2
destruct! 10
useSimple freed!
*/
int main(int argc, char **argv)
{
#if 0
	auto share_simple { make_shared<Simple>(10) };
	//访问类成员用->, 访问shared_ptr成员函数用.
	fmt::print("share_simple: {} use_count:{}\n", share_simple->m_data, share_simple.use_count());

	weak_ptr<Simple> weak_simple { share_simple };
	useSimple(weak_simple);

	share_simple.reset();
	useSimple(weak_simple);
#else
	shared_ptr<Simple> s2 { make_shared<Simple>(20) };	
	fmt::print("use_count:{} m_data:{}\n", s2.use_count(), s2->m_data);
	useSimpleShared(s2);
	fmt::print("use_count:{} m_data:{}\n", s2.use_count(), s2->m_data);
#endif
	return 0;
}

