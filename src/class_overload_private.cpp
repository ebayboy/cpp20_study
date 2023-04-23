
#include <fmt/core.h>

#include <iostream>
#include <utility>

// 16.6.4 3.重写基类的private方法

using namespace std;

class Base {
public:
    Base() : m_gallons(2){};
    Base(int i) : m_gallons(i){};
    int virtual getMilesLeft(){ return getMilesPerGallon() * m_gallons; };

private:
    int m_gallons{0};
    int virtual getMilesPerGallon() { return 20; };
};

class Drived : public Base {
private: 
    int getMilesPerGallon() override { return 40; }; //重写基类的getMilesPerGallon方法
};

int main(int argc, char **argv) {
    Base b{2};
	fmt::println("getMilesLeft:{}", b.getMilesLeft());

	Drived d;
	fmt::println("getMilesLeft:{}", d.getMilesLeft()); //会调用重写后的私有方法

    return 0;
}

