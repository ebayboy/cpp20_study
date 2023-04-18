
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
		void virtual eat() {
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
		void virtual eat() {
			cout << "bird eat!\n";
		};
	private:
		int m_data;
};

class DogBird : public Dog, public Bird {
	public:
		//2. 在派生类中重写eat，在重新方法中指定调用哪个基类的eat

#if 0	
		//2.1 	
		void eat() override {
			Dog::eat();
		};
#else 
		//2.2
		using Dog::eat;
#endif

};


int main(int argc, char **argv)
{
	DogBird db;
	
	db.bark();
	db.chirp();

	db.eat(); //1. error: request for member ‘eat’ is ambiguous, Bird和Dog中都有eat，调用会混淆

	return 0;
}

