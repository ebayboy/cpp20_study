
#include <iostream>
#include <utility>
#include <fmt/core.h>

using namespace std;

class Base {
	public:
		Base(): m_gallons(2) {};
		Base(int i) : m_gallons(i) {};
		void virtual getMilesLeft() { };
	private:
		int m_gallons { 0 };
		int getMilesPerGallon() {
			return 20;	
		};
};

class Drived : public Base {
	public:
};

int main(int argc, char **argv)
{
	Base b;

	return 0;
}

