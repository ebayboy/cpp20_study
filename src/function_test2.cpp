
#include <fmt/core.h>

#include <functional>
#include <iostream>
#include <utility>

using namespace std;

/// 函数对象包装器function

#if 0
int g_Minus(int i, int j)
{
	return i - j;
}

int main(int argc, char **argv)
{
	//1. 包装普通函数
	function<int(int, int)> f = g_Minus;
	cout << f(1,2) << endl;
	return 0;
}
#endif

#if 0
//2. 保证模板函数
template<class T>
T g_Minus(T i, T j)
{
	return i - j;
}

int main(int argc, char **argv)
{
	function<int(int,int)> f2 = g_Minus<int>; //g_Minus<int> 模板实例化
	fmt::println("f2:{}", f2(1,2));

	return 0;
}
#endif

#if 0
// 3. 包装lambda函数
auto g_Minus = [](int i, int j) { return i - j; };
int main()
{
	function<int(int, int)> f = g_Minus;
	cout << f(1,2) << endl;
	return 0;
};
#endif

// 4. 包装函数对象

#if 0
// 非模板类型
class Minus {
	public:
		int operator() (int i, int j)
		{
			return i - j;
		};
};

int main()
{
	std::function<int(int, int)> f = Minus();
	cout << f(1,2) << endl;

	return 0;
}
#endif

#if 0
// 4.2 模板类型
template<class T>
class Minus {
	public:
		T operator() (T i, T j)
		{
			return i - j;
		};
};

int main()
{
	std::function<int(int, int)> f = Minus<int>();
	cout << f(1,2) << endl;
	return 0;
}
#endif

// 5. 包装类静态成员函数
#if 0
// 5.1 非模板类型
class Math {
	public:
		static int Minus(int i, int j)
		{
			return i - j;
		};
};
int main()
{
	std::function<int(int, int)> f = Math::Minus;
	cout << f(1,2) << endl;
	return 0;
}
#endif

#if 0
// 5.2 模板类型
class Math {
	public:
		template<class T>
		static T Minus(T i, T j)
		{
			return i - j;
		};
};
int main()
{
	std::function<int(int, int)> f = &Math::Minus<int>;
	cout << f(1,2) << endl;
	return 0;
};

#endif

// 6. 包装类成员函数
#if 0
// 6.1 非模板类型
class Math {
	public:
		int Minus(int i, int j)
		{
			return i -j ;
		};
};
int main()
{
	Math m;
	cout << m.Minus(1,2) << endl;
	return 0;
}
#endif

#if 0
// 6.2 模板类型
class Math {
	public:
		template<class T>
		T Minus(T i, T j)
		{
			return i -j ;
		};
};
int main()
{
	Math m;
	cout << m.Minus<int>(1,2) << endl;
	return 0;
}
#endif

#if 0
// 7. 拷贝、移动
int callback(int p)
{
	return p;
}
int main()
{
	//拷贝
	std::function<int(int)> f = callback;
	cout << f(7) << endl;

	//move移动
	std::function<int(int)> f2= std::move(callback);
	cout << f(6) << endl;

	//拷贝
	std::function<int(int)> f3(callback);
	cout << f3(5) << endl;

	return 0;
}
#endif

// 8. function做参数

int func1(int i, int j)
{
	cout << "func1\n";
	return i-j;
}

int func2(std::function<int(int,int)> handler)
{
	return handler(1,2);
}

int main() { 

	//用法1
	std::function<int(int,int)> f = func1;
	func2(f);

	//用法2
	func2(func1);

	return 0; 
}

