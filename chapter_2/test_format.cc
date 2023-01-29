
#include <iostream>
#include <utility>
#include <fmt/core.h>

using namespace std;
using namespace fmt;

//fmt::format用法
int main(int argc, char **argv)
{
	int n {5};
	string filename {"file1.txt"};
	auto s1 { fmt::format("Read {0} bytes from {1}", n, filename) }; //可以指定index, {index}
	fmt::print("s1:{}\n", s1);

	//指定width
	int i {42};	
	cout << fmt::format("|{:5}|\n", i); //指定输出宽度， 类型%05d
	cout << fmt::format("|{:{}}|\n", i, 7);

	//align： 指定填充字符和对齐方式
	cout << format("|{:<5}|\n", i);  //左对齐
	cout << format("|{:>5}|\n", i);  //右对齐, 默认对齐方式
	cout << format("|{:^5}|\n", i);  //居中对齐
	cout << format("|{:_^5}|\n", i);  //居中对齐，使用_填充
	
	//sign == -
	//默认方式， 只显式负数符号; +:显式负数和正数的符号； space:-表示负数，空格表示正数
	cout << format("|{:<-5}|\n", i);  //左对齐, 只显示负数的符号
	cout << format("|{:<-5}|\n", -i);  //左对齐

	//sign == + 
	cout << format("|{:<+5}|\n", i);  //左对齐, 只显示负数的符号
	cout << format("|{:<+5}|\n", -i);  //左对齐

	//sign == space
	cout << format("|{:< 5}|\n", i);  //左对齐, 只显示负数的符号
	cout << format("|{:< 5}|\n", -i);  //左对齐

	//备用格式： #, 如果指定了16进制或8进制数字格式， 则在前面插入0x/0X/0b/0B或0
	cout << format("|{:10d}|", i) << endl; //10进制格式化 
	cout << format("|{:10b}|", i) << endl; //2进制格式化
	cout << format("|{:#10b}|", i) << endl; 
	cout << format("|{:10x}|", i) << endl; 
	cout << format("|{:#10x}|", i) << endl; 

	//精度precision
	double d { 3.1415/2.3 };
	cout << format("|{:12g}|", d) << endl;
	cout << format("|{:12.2}|", d) << endl; //1.4
	cout << format("|{:12e}|", d) << endl;
	cout << format("2:{0}.{1}f", 12, 3, d) << endl;

	return 0;
}

