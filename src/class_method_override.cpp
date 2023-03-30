
#include <iostream>
#include <utility>
#include <fmt/core.h>

using namespace std;

class Base {
	public:
		virtual void method1() { fmt::println("Base method1"); }
	
	private:
		int m_data;
};

class Drived : public Base {
	public:
		// override 必须与 virtual 配对使用
		void method1() override { fmt::println("Drived method1"); }
		void method2() { fmt::println("Drived method2"); }
};

int main(int argc, char **argv)
{
	Drived d;
	d.method1();

	return 0;
}

