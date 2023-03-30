
#include <iostream>
#include <utility>
#include <fmt/core.h>

using namespace std;

class Base {
	public:
		//1. 有virtual可以被继承类重写
		virtual void method1() { fmt::println("Base method1"); }
		virtual void method2() { fmt::println("Base method2"); }

		//2. 没有virtual, 只能被继承类隐藏， 但是可以通过Base类引用调用Base类的method3
		void method3() { fmt::println("Base method3"); }
	
	private:
		int m_data;
};

class Drived : public Base {
	public:

		// override关键字, 显示重写： override 必须与 virtual 配对使用
		void method1() override { fmt::println("Drived method1"); }

		//隐式重写, 没有override关键字，不推荐
		void method2() { fmt::println("Drived method2"); }
	
		// 由于Base method3没有virtual关键字， 这里只是隐层了Base的method3方法	
		void method3() { fmt::println("Drived method3"); }

		void method4() { fmt::println("Drived method4"); }
};

int main(int argc, char **argv)
{
	// 1. 方法重写
	Drived d;
	fmt::println("{}:{}", __func__, __LINE__);
	d.method1(); //Drived method1
	d.method2(); //Drived method2

	fmt::println("{}:{}", __func__, __LINE__);
	Base & b {d};
	b.method1(); //Drived method1
	b.method2(); //Drived method2

	//被隐藏的method3, Base引用可以调用Base的method3方法 
	b.method3(); //Base method3

	fmt::println("{}:{}", __func__, __LINE__);
	// 将Drived转换为Base对象
	Base b1 {d};
	b.method1(); //Drived method1
	
	fmt::println("{}:{}", __func__, __LINE__);
	Base b2;
	b2.method1(); //Base method1

	return 0;
}

