// foo.cppm
module; 
export module foo;  // 为模块 "foo" 声明主模块接口单元

import <iostream>;

// 对模块外部**不可见**的函数声明与实现
void FooFuncInternal() { std::cout << "Foo!" << std::endl; }

// 对模块外部可见的函数声明与实现，通过 export 修饰
export void FooFunc() { FooFuncInternal(); }

