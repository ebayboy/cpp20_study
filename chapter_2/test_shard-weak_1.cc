
#include <iostream>
#include <utility>
#include <fmt/core.h>

#include <memory>

using namespace std;

//声明
class A;
class B;

class C;
class D;


//定义A && B, A && B互相强引用
class A
{
public:
	A (int value) : m_data { value } { cout <<"construct A..\n";  };
	~A () { cout <<"destruct A!\n";  };
	shared_ptr<B> ptr;
	int m_data;
};

class B
{
public:
	B (int value) : m_data { value } { cout <<"construct B..\n";  };
	~B () { cout <<"destruct B!\n";  };
	shared_ptr<A> ptr;
	int m_data;
};

void test_mem_leak()
{
	auto a { make_shared<A>(111) };
	auto b { make_shared<B>(222) };

	//互相引用，导致内存泄露
	a->ptr = b;
	b->ptr = a;

	a.reset();
	fmt::print("a.reset... a.use:{} b.use:{}\n", a.use_count(), b.use_count());

	b.reset();
	fmt::print("b.reset... a.use:{} b.use:{}\n", a.use_count(), b.use_count());
	
	//construct A..
	//construct B..
	//a.reset... a.use:0 b.use:2
	//b.reset... a.use:0 b.use:0
	//a和b的引用计数都为0，但并没有调用析构函数， 造成内存泄露
}

// C && D 互相弱引用
class C
{
public:
	C (int value) : m_data { value } { cout <<"construct C..\n";  };
	~C () { cout <<"destruct C!\n";  };
	weak_ptr<D> ptr;
	int m_data;
};

class D
{
public:
	D (int value) : m_data { value } { cout <<"construct D..\n";  };
	~D () { cout <<"destruct D!\n";  };
	weak_ptr<C> ptr;
	int m_data;
};

//弱引用没有互相增加引用计数， 没有阻止资源释放
void test_mem_weak_ptr()
{
	auto c { make_shared<C>(111) };
	auto d { make_shared<D>(222) };

	//互相引用，导致内存泄露
	c->ptr = d;
	d->ptr = c;

	c.reset();
	fmt::print("reset... c.use:{} d.use:{}\n", c.use_count(), d.use_count());

	d.reset();
	fmt::print("reset... c.use:{} d.use:{}\n", c.use_count(), d.use_count());
	/*
	   construct C..
	   construct D..
	   destruct C!
	   reset... c.use:0 d.use:1
	   destruct D!
	   reset... c.use:0 d.use:0
	*/
}

int main(int argc, char **argv)
{
#if 0
	// 测试成员互相强引用版本
	test_mem_leak();
#endif

	// 测试成员互相弱引用版本
	test_mem_weak_ptr();
	
	return 0;
}

