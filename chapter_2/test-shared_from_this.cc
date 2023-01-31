
#include <iostream>
#include <memory>
#include <utility>

#include <fmt/core.h>

using namespace std;

//enable_shared_from_this + shared_from_this：不会造成内存二次释放
class Simple : public enable_shared_from_this<Simple>
{
public:
	shared_ptr<Simple> getPointer()
	{
		return shared_from_this();
	};
	Simple (int v) : m_data { v } { cout << "construct...\n"; };
	~Simple () { cout << "destruct!\n"; };
	int m_data;
};

//Error: 二次释放内存
class Simple2
{
public:
	shared_ptr<Simple2> getPointer()
	{
		return shared_ptr<Simple2>(this); //Error
	};
	Simple2 (int v) : m_data { v } { cout << "construct...\n"; };
	~Simple2 () { cout << "destruct!\n"; };
	int m_data;
};

int main(int argc, char **argv)
{
#if 0
	shared_ptr<Simple> s { make_shared<Simple>(10) };
	auto ptr2 { s->getPointer() };
	fmt::print("m_data:{} ptr2->m_data:{}\n", s->m_data, ptr2->m_data);
#else
	shared_ptr<Simple2> s { make_shared<Simple2>(20) };
	auto ptr2 { s->getPointer() }; //Error: double free or corruption (out)
	fmt::print("m_data:{} ptr2->m_data:{}\n", s->m_data, ptr2->m_data);
#endif

	return 0;
}

