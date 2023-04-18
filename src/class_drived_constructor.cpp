
#include <fmt/core.h>

#include <iostream>
#include <string>
#include <utility>

using namespace std;

// 使用using继承基类构造函数

class Base {
public:
    Base() { cout << "Base()" << endl; }; 
    virtual ~Base(){  };
    Base(float f) { cout << "f:" << f << endl; };
    Base(string_view s) { cout << "s:" << s << endl; };
};

class Drived : public Base {
public:
	Drived() { cout << "Drived()\n"; };
    Drived(int i) { cout << "Drived i:" << i << endl; };
	//继承基类构造函数
	using Base::Base;
};

int main(int argc, char **argv) {

	float f {1.11};
    Drived d(f);

    Drived d1{"hello"};

	cout << "11==========\n";
    Drived d2{};
	cout << "22==========\n";

    return 0;
}

