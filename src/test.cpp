
#include <iostream>
#include <utility>
#include <fmt/core.h>
#include <vector>

// 成员函数声明时可以没有形参， 但定义时需要有形参a

using namespace std;

class Epoll {
	public:
		Epoll() {};
		virtual ~Epoll() {};
		virtual void EpollAdd(int);
};

void Epoll::EpollAdd(int a)
{
	cout << "a:" << a << endl;	
}

int main(int argc, char **argv)
{
	Epoll e;

	e.EpollAdd(10);

	return 0;
}

