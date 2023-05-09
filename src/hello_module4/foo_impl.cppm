
// foo_impl.cppm
module;  // 同样地，为了 include 非模块化的代码头文件，先声明全局（global）模块单元

#include <iostream>

module foo;  // 声明私有模块片段 foo
             // 在实现文件中，**无需**使用 export 修饰
// 定义函数实现
void FooFunc() { std::cout << "Foo!" << std::endl; }
