
#include <iostream>
#include <limits>
#include <stdexcept>

using namespace std;

void MyFunc() { throw invalid_argument("MyFunc argument too large."); }

// try捕获函数块
void MyFunc2() try {
    throw invalid_argument("MyFunc argument too large.");
} catch (invalid_argument& e) {
    cerr << "MyFunc2 catch: " << e.what() << endl;
    return;
}

int main() {
#if 0
    // 1. 在调用代码中捕获异常
    try {
	MyFunc();
    }

    catch (invalid_argument& e) {
	cerr << "catch: " << e.what() << endl;
	return -1;
    }
#else
    // 2. 在调用代码中捕获异常
    MyFunc2();
#endif

    return 0;
}
