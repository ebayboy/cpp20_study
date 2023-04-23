
#include <iostream>
#include <utility>
#include <fmt/core.h>

using namespace std;


class Base {
	public:
		virtual void talk() { cout << "Base talk\n"; };
	protected:
		virtual void talk2() { cout << "Base talk2\n"; };
};

class Drived : public Base {
	public:
		using Base::talk2; //1. 使用using修改访问级别
		void getTakl() {
			talk();
		};
		
	protected:
		using Base::talk; // 权限缩小
		//void talk() override { cout << "Drived talk\n"; };
};

int main(int argc, char **argv)
{
	Drived d;
	//d.talk(); //Error: 无法在外部直接访问protected成员 

	Base &ref {d};
	ref.talk();

	// 调用使用using放大权限的方法
	d.talk2();

	//ref.talk2(); //Error: 基类的protected方法依然受保护， 不能直接调用

	d.getTakl();

	//d.talk(); // Error: 无法直接调用protected方法

	return 0;
}

