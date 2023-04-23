
#include <fmt/core.h>

#include <iostream>
#include <utility>

using namespace std;

class Base {
public:
    Base() : m_gallons(2){};
    Base(int i) : m_gallons(i){};
    int virtual getMilesLeft(){ return getMilesPerGallon() * m_gallons; };

private:
    int m_gallons{0};
    int getMilesPerGallon() { return 20; };
};

class Drived : public Base {
public:
};

int main(int argc, char **argv) {
    Base b{2};



    return 0;
}

