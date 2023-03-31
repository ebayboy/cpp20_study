
#include <fmt/core.h>

#include <iostream>
#include <utility>

using namespace std;

class Base {
public:
    Base(){};
	
	//如果析构函数不生命为virtual， 则会继承类的析构函数不会被调用， 造成内存泄露
    virtual ~Base() = default;
private:
};

class Drived : public Base {
	public: 
		Drived() {
			m_string = new char[30];
			cout << "m_string allocated" << endl;
		};
		~Drived() {
			delete[] m_string;
			cout << "m_string deleted!" << endl;
		};
	private:
		char *m_string;
};

int main(int argc, char **argv) {

	Base *ptr { new Drived()  };
	delete ptr;

    return 0;
}

