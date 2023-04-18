
#include <iostream>
#include <utility>
#include <fmt/core.h>

//基类Dog和Bird中都有eat， 派生类继承Dog和Bird, 如果调用eat会产生混淆报错， 不调用则没事

using namespace std;

class Dog {
	public:
		void bark() {
			cout << "dog bark\n";
		};
		void eat() {
			cout << "dog eat!\n";
		};
	private:
		int m_data;
};

class Bird {
	public:
		void chirp() {
			cout << "bird chirp!\n";
		};
		void eat() {
			cout << "bird eat!\n";
		};
	private:
		int m_data;
};

class DogBird : public Dog, public Bird {
};


int main(int argc, char **argv)
{
	DogBird db;
	
	db.bark();
	db.chirp();

	db.eat(); //error: request for member ‘eat’ is ambiguous, Bird和Dog中都有eat，调用会混淆

	return 0;
}

