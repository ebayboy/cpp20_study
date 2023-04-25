
#include <fmt/core.h>

#include <iostream>
#include <typeinfo>
#include <utility>

using namespace std;

// 抽象类
class Loggable {
    virtual ~Loggable() = default;
    virtual string getLogMessage() const = 0;  // 纯虚函数
};

class Foo : public Loggable {
public:
    string getLogMessage() const override { return "Hello logger!"; };
};

void logObject(const Loggable &logableObject) {
    cout << typeid(logableObject).name() << ":";
    cout << logableObject.getLogMessage() << endl;
}

int main(int argc, char **argv) { return 0; }

