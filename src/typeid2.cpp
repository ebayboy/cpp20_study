
#include <fmt/core.h>

#include <iostream>
#include <typeinfo>
#include <utility>

using namespace std;

// typeid用法

// 抽象类
class Loggable {
    virtual string getLogMessage() const = 0;  // 纯虚函数
};

class Foo : public Loggable {
public:
    string getLogMessage() const override { return "Hello logger!"; };
};

void logObject(const Foo &foo) {
    cout << "typeid.name():" << typeid(foo).name() << endl;
    cout << "getLogMessage:" << foo.getLogMessage() << endl;
}

int main(int argc, char **argv) { 

	Foo fo;

	cout << "fo.getLogMessage:" << fo.getLogMessage() << endl;;

	logObject(fo);

	return 0; 
}

