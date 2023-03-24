
#include <iostream>

using namespace std;

// 对引用取地址，实际上是对引用的原变量取地址
int main(int argc, char **argv) {
    // 定义一个int型变量a并赋初值
    int a = 10;

    // 定义一个引用b为a的一个引用
    int &b = a;

    // 对b进行赋值操作就是对a本身的操作，也就是a的值被赋值为5
    b = 5;

    cout << "&a:" << &a << endl;

    // 对引用b进行取址后输出
    cout << "&b:" << &b << endl;

    cout << "b:" << b << endl;
    ;

    return 0;
}

